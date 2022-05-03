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

float symbols_in_min(char* user_str, float time)
{
    int len = sizeof(user_str);
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