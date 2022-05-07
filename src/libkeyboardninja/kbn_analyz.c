#include <libkeyboardninja/kbn_analyz.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* analyz(char* spec_string, char* user_string, int* size)
{
    int i = 0, cnt = 1;
    while (user_string[i] != '\0') {
        i++;
        cnt++;
    }
    int* analyz = (int*)malloc(cnt * sizeof(int));
    i = 0;
    while (spec_string[i] != '\n') {
        if (user_string[i] == -48 || user_string[i] == -47) {
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
    int len = strlen(user_str);
    if (lang == 1)
        len /= 2;
    float sim = (len * 60) / time;
    return sim;
}

void print_rate(float sym_in_min)
{
    if (sym_in_min <= 50)
        printf("Неуверенный\n");
    else if (sym_in_min > 50 && sym_in_min <= 100)
        printf("Осваивающийся\n");
    else if (sym_in_min > 100 && sym_in_min <= 150)
        printf("Начинающий\n");
    else if (sym_in_min > 150 && sym_in_min <= 200)
        printf("Дефолтный пользователь\n");
    else if (sym_in_min > 200 && sym_in_min <= 250)
        printf("Уверенный пользователь\n");
    else if (sym_in_min > 250 && sym_in_min <= 300)
        printf("Продвинутый пользователь\n");
    else if (sym_in_min > 300 && sym_in_min <= 350)
        printf("Наборщик\n");
    else if (sym_in_min > 350 && sym_in_min <= 400)
        printf("Наборщик со стажем\n");
    else if (sym_in_min > 400 && sym_in_min <= 450)
        printf("Печатная машинка\n");
    else if (sym_in_min > 450 && sym_in_min <= 500)
        printf("Робот\n");
    else if (sym_in_min > 500)
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

void incorrect_output(char* user_str, int* analyz_print, int cnt)
{
    printf("\033[1;31m");
    printf("\n\t***Строка была введена неверно!***\n\tОшибки "
           "представлены "
           "ниже\n");
    printf("\033[1;37m");
    for (int i = 0; i < cnt - 1; i++) {
        if (analyz_print[i] == 1) {
            if (user_str[i] == -48 || user_str[i] == -47) {
                printf("\033[32m");
                printf("%c", user_str[i]);
                i++;
                printf("%c", user_str[i]);
            } else {
                printf("\033[32m%c", user_str[i]);
            }
        } else {
            if (user_str[i] == -48 || user_str[i] == -47) {
                printf("\033[31m");
                printf("%c", user_str[i]);
                i++;
                printf("%c", user_str[i]);
            } else {
                printf("\033[31m%c", user_str[i]);
            }
        }
    }
}

void correct_output(double time, char* user_str, int lang)
{
    printf("\033[1;32m");
    printf("\n\t***Строка была введена верно***\nАнализ представлен  "
           "ниже\n");
    printf("Время, за которое была введена строка: %0.2f\n", time);
    float sym_in_min = symbols_in_min(user_str, time, lang);
    printf("Скорость набора : %.2f(сим/сек)\n", sym_in_min);
    printf("Ранг - ");
    print_rate(sym_in_min);
}

void print_less_cnt_sym()
{
    printf("\033[31m");
    printf("\n\tОбнаружена ошибка!\nВведено меньше символов, чем в требуемой "
           "строке\n");
    printf("\033[37m");
}