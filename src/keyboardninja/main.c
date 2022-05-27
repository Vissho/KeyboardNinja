#include <keyboardninja/kbn_print_banner.h>
#include <libkeyboardninja/colors_output.h>
#include <libkeyboardninja/kbn_analyz.h>
#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");

    int true_flag = 1;
    int lang, coml;
    int cnt = SIZE_DICTIONARY;
    double time;

    char** dict = read_dictionary(cnt);

    print_banner();
    learn_settings(&lang, &coml);

    char* spec_string = specified_string(dict, lang, coml, cnt);
    char* user_str = user_string(&time, spec_string);
    int* analyz_print = analyz(spec_string, user_str, &cnt);

    size_t len = strlen(spec_string) - 1;
    true_flag = correct_str(analyz_print, len);

    if (true_flag == 1) {
        correct_output(time, user_str);
    } else {
        incorrect_output(user_str, spec_string, analyz_print, cnt - 1, time);
    }
    printf("\033[37m");
    printf("\n");

    free_all(user_str, analyz_print, dict);
}