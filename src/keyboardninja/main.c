#include <keyboardninja/kbn_print_banner.h>
#include <libkeyboardninja/kbn_analyz.h>
#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <string.h>
#define STRING_SIZE_MAX 70

int main()
{
    int true_flag;
    int lang, coml;
    float sym_in_min;
    int cnt;
    double time;
    char** dict = read_dictionary(&cnt);
    print_banner();
    learn_settings(&lang, &coml);
    char* spec_string = find_string(dict, lang, coml, cnt);
    char* user_str = user_string(&time, spec_string);
    int* analyz_print = analyz(spec_string, user_str, &cnt);
    true_flag = 1;
    for (int x = 0; x < cnt - 1; x++)
        if (analyz_print[x] != 1) {
            true_flag = 0;
        }
    if (true_flag == 1) {
        printf("\033[1;32m");
        printf("\n\t***Строка была введена верно***\nАнализ представлен  "
               "ниже\n");
        printf("Время, за которое была введена строка: %0.2f\n", time);
        sym_in_min = symbols_in_min(user_str, time);
        printf("Скорость набора : %.2f(сим/сек)\n", sym_in_min);
        printf("Ранг: ");
        print_rate(sym_in_min);
    } else {
        printf("\033[1;31m");
        printf("\n\t***Строка была введена неверно!***\n\tОшибки "
               "представлены "
               "ниже\n");
        printf("\033[1;37m");
        for (int i = 0; i < cnt; i++) {
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
    printf("\033[37m");
    printf("\n");
    return 0;
}