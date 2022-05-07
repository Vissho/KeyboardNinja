#include <keyboardninja/kbn_print_banner.h>
#include <libkeyboardninja/kbn_analyz.h>
#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int true_flag = 1, lenflag;
    int lang, coml;
    int cnt = 300;
    double time;

    char** dict = read_dictionary(cnt);

    print_banner();
    learn_settings(&lang, &coml);

    char* spec_string = find_string(dict, lang, coml, cnt);
    char* user_str = user_string(&time, spec_string);
    int* analyz_print = analyz(spec_string, user_str, &cnt);

    size_t len = strlen(spec_string) - 1;
    true_flag = correct_str(analyz_print, len);
    lenflag = correct_len(spec_string, user_str, lang);

    if (true_flag == 1 && lenflag == 0) {
        correct_output(time, user_str, lang);
    } else {
        if (lenflag == -1) {
            print_less_cnt_sym();
        } else if (lenflag == 0 || lenflag == 1) {
            incorrect_output(user_str, analyz_print, cnt - 1);
        }
    }
    printf("\033[37m");
    printf("\n");
}