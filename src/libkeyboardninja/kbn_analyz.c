#include <libkeyboardninja/colors_output.h>
#include <libkeyboardninja/kbn_analyz.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lvls_skill_user[]
        = {"Осваивающийся",
           "Практикующийся",
           "Начинающий",
           "Дефолтный пользователь",
           "Умелый пользователь",
           "Продвинутый пользователь",
           "Наборщик",
           "Наборщик со стажем",
           "Печатная машинка",
           "Робот",
           "Киберпсих"};

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

float symbols_in_min(char* user_str, float time)
{
    int cnt_sym = 0;
    int i = 0;
    int sec_in_min = 60;
    while (user_str[i] != '\0') {
        if (user_str[i] == RU_UPPER_CASE || user_str[i] == RU_LOWER_CASE)
            i += 2;
        else
            i++;
        cnt_sym++;
    }
    float sim = (cnt_sym * sec_in_min) / time;
    return sim;
}

int calculate_rate(float sym_in_min)
{
    int cnt_lvls = 11;
    int cnt_min_diff = 50;
    int* lvls_user_speed = calloc(cnt_lvls, sizeof(int));

    for (int x = 0; x < cnt_lvls; x++) {
        lvls_user_speed[x] += cnt_min_diff;
        cnt_min_diff += 50;
    }

    struct rank arr_ranks[cnt_lvls];

    for (int x = 0; x < cnt_lvls; x++) {
        arr_ranks[x].key = lvls_skill_user[x];
        arr_ranks[x].value = lvls_user_speed[x];
    }

    for (int x = 0; x < cnt_lvls; x++) {
        if (sym_in_min < arr_ranks[x].value)
            return x;
    }
    return 10;
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
        double time)
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
    float sym_in_min = symbols_in_min(user_str, time);
    int rank = calculate_rate(sym_in_min);
    printf("Скорость набора : %.2f(сим/сек)\n", sym_in_min);
    printf("Ранг - %s\n", lvls_skill_user[rank]);
    printf("%s", GREEN);
    printf("\n\nНеплохой результат, ждём Вас снова!\n\n");
}

void correct_output(double time, char* user_str)
{
    printf("%s", WHITE);
    printf("\n\t***Строка была введена верно***\n\tАнализ представлен  "
           "ниже\n");
    printf("Время, за которое была введена строка: %0.2f\n", time);
    float sym_in_min = symbols_in_min(user_str, time);
    printf("Скорость набора : %.2f(сим/сек)\n", sym_in_min);
    int rank = calculate_rate(sym_in_min);
    printf("Ранг - %s\n", lvls_skill_user[rank]);
    printf("%s", GREEN);
    printf("\n\nНеплохой результат, ждём Вас снова!\n\n");
}