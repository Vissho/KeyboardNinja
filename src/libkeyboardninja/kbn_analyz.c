#include <libkeyboardninja/colors_output.h>
#include <libkeyboardninja/kbn_analyz.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    NOT_CONFIDENT = 50,
    MASTERED = 100,
    BEGINNER = 150,
    DEFAULT_USER = 200,
    CONFIDENT_USER = 250,
    ADVANCED_USER = 300,
    TYPER = 350,
    EXP_TYPER = 400,
    TYPE_MACHINE = 450,
    ROBOT = 500,
    CYBERPSICHO = 550
} lvls_skill_user;

int* analyz(char* spec_string, char* user_string, int* size)
{
    int i = 0, user_cnt = strlen(user_string), spec_cnt = 1, cnt = 1;
    while (spec_string[i] != '\n') {
        i++;
        spec_cnt++;
    }
    cnt = (user_cnt > spec_cnt) ? user_cnt : spec_cnt;
    int* analyz = (int*)malloc(cnt * sizeof(int));
    i = 0;
    while (spec_string[i] != '\n') {
        if (user_string[i] == RU_UPPER_CASE
            || user_string[i] == RU_LOWER_CASE) {
            if (user_string[i] == spec_string[i]
                && user_string[i + 1] == spec_string[i + 1]) {
                analyz[i] = 1;
                i++;
                analyz[i] = 1;
            } else {
                analyz[i] = 0;
                i++;
                analyz[i] = 0;
            }
        } else {
            if (user_string[i] == spec_string[i]) {
                analyz[i] = 1;
            } else {
                analyz[i] = 0;
            }
        }
        i++;
    }
    while (i < cnt) {
        analyz[i] = 0;
        i++;
    }
    *size = cnt - 1;
    return analyz;
}

float symbols_in_min(char* user_str, float time, int lang)
{
    int sec_in_min = 60;
    int len = strlen(user_str);
    if (lang == 1)
        len /= 2;
    float sim = (len * sec_in_min) / time;
    return sim;
}

void print_rate(float sym_in_min)
{
    if (sym_in_min <= NOT_CONFIDENT)
        printf("Неуверенный\n");
    else if (sym_in_min > NOT_CONFIDENT && sym_in_min <= MASTERED)
        printf("Осваивающийся\n");
    else if (sym_in_min > MASTERED && sym_in_min <= BEGINNER)
        printf("Начинающий\n");
    else if (sym_in_min > BEGINNER && sym_in_min <= DEFAULT_USER)
        printf("Дефолтный пользователь\n");
    else if (sym_in_min > DEFAULT_USER && sym_in_min <= ADVANCED_USER)
        printf("Уверенный пользователь\n");
    else if (sym_in_min > ADVANCED_USER && sym_in_min <= TYPER)
        printf("Продвинутый пользователь\n");
    else if (sym_in_min > TYPER && sym_in_min <= EXP_TYPER)
        printf("Наборщик\n");
    else if (sym_in_min > EXP_TYPER && sym_in_min <= TYPE_MACHINE)
        printf("Наборщик со стажем\n");
    else if (sym_in_min > TYPE_MACHINE && sym_in_min <= ROBOT)
        printf("Печатная машинка\n");
    else if (sym_in_min > ROBOT && sym_in_min <= CYBERPSICHO)
        printf("Робот\n");
    else if (sym_in_min > CYBERPSICHO)
        printf("КИБЕРПСИХ\n");
}

int correct_str(int* arr, size_t len)
{
    for (size_t x = 0; x < len; x++)
        if (arr[x] != 1) {
            return 0;
        }
    return 1;
}

void incorrect_output(
        char* user_str,
        char* spec_string,
        int* analyz_print,
        int cnt,
        double time,
        int lang)
{
    printf("%s", YELLOW);
    printf("\n\t***Строка была введена неверно!***\n\t     Ошибки "
           "представлены "
           "ниже\n");
    printf("%s\n", WHITE);
    int i;
    for (i = 0; i < cnt - 1; i++) {
        if (user_str[i] == '\n' && spec_string[i] != '\0') {
            break;
        } else {
            if (analyz_print[i] == 1) {
                if (user_str[i] == RU_UPPER_CASE
                    || user_str[i] == RU_LOWER_CASE) {
                    printf("%s", GREEN);
                    printf("%c", user_str[i]);
                    i++;
                    printf("%c", user_str[i]);
                } else {
                    printf("%s%c", GREEN, user_str[i]);
                }
            } else {
                if (user_str[i] == RU_UPPER_CASE
                    || user_str[i] == RU_LOWER_CASE) {
                    printf("%s", RED);
                    printf("%c", user_str[i]);
                    i++;
                    printf("%c", user_str[i]);
                } else {
                    printf("%s%c", RED, user_str[i]);
                }
            }
        }
    }
    while (spec_string[i] != '\0') {
        if (spec_string[i] == RU_UPPER_CASE
            || spec_string[i] == RU_LOWER_CASE) {
            printf("%s", RED);
            printf("%c", spec_string[i]);
            i++;
            printf("%c", spec_string[i]);
        } else {
            printf("%s%c", RED, spec_string[i]);
        }
        i++;
    }
    printf("%s", WHITE);
    printf("\n\tАнализ представлен  "
           "ниже\n");
    printf("Время, за которое была введена строка: %0.2f\n", time);
    float sym_in_min = symbols_in_min(user_str, time, lang);
    printf("Скорость набора : %.2f(сим/сек)\n", sym_in_min);
    printf("Ранг - ");
    print_rate(sym_in_min);
    printf("%s", GREEN);
    printf("\n\nНеплохой результат, ждём Вас снова!\n\n");
}

void correct_output(double time, char* user_str, int lang)
{
    printf("%s", WHITE);
    printf("\n\t***Строка была введена верно***\n\tАнализ представлен  "
           "ниже\n");
    printf("Время, за которое была введена строка: %0.2f\n", time);
    float sym_in_min = symbols_in_min(user_str, time, lang);
    printf("Скорость набора : %.2f(сим/сек)\n", sym_in_min);
    printf("Ранг - ");
    print_rate(sym_in_min);
    printf("%s", GREEN);
    printf("\n\nНеплохой результат, ждём Вас снова!\n\n");
}