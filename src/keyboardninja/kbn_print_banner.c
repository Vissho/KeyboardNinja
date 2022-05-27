#include <assert.h>
#include <ctype.h>
#include <keyboardninja/kbn_print_banner.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_banner()
{
    printf("\033[31m");
    printf("\n__   __           _                         _ _   _ _       "
           "_\n| | / /          | |                       | | \\ | (_)     "
           "(_)      \n| |/ /  ___ _   _| |__   ___   __ _ _ __ __| |  \\| "
           "|_ "
           "_ __  _  __ _ \n|    \\ / _ \\ | | | '_ \\ / _ \\ / _` | '__/ _` "
           "| . "
           "` | | '_ \\| |/ _` |\n| |\\  \\  __/ |_| | |_) | (_) | (_| | | | "
           "(_| | |\\  | | | | | | (_| |\n\\_| \\_/\\___|\\__, |_.__/ \\___/ "
           "\\__,_|_|  \\__,_\\_| \\_/_|_| |_| |\\__,_|\n             __/ |  "
           "     "
           "                                 _/ |      \n            |___/   "
           "                                     |__/ \n");
    printf("             *******************************************\n"
           "            * Вас приветствует программа KeyboardNinja! *\n"
           "             *******************************************\n");
    printf("\n");
    printf("\033[37m");
}

void print_lang()
{
    printf("       ***Введите цифру соответственно выбранному Вами "
           "языка***\n"
           "                 1 - Русский язык (Russian)\n"
           "                 2 - Английский язык (English)\n");
}

void print_coml()
{
    printf("    ***Введите желаемый уровень сложности соответственно "
           "цифре***\n"
           "                    1 - Легкий\n"
           "                    2 - Средний\n"
           "                    3 - Сложный\n");
}

int learn_lang()
{
    char* p = malloc(10 * sizeof(char));
    while (1) {
        printf(": ");
        fgets(p, 10, stdin);
        if (strlen(p) == 2) {
            if (p[0] == '1' || p[0] == '2') {
                return p[0] - '0';
            }
            if (isdigit(p[0])) {
                printf("[E] Введен неизвестный язык! Повтор ввода");
                continue;
            }
            if (p[0] == 'q') {
                free(p);
                printf("[E] Выход из программы...");
                return -1;
            }
            printf("[E] Введен неизвестный символ! Повтор ввода");
        } else
            printf("[E] Введен неизвестный символ! Повтор ввода");
    }
    assert(0 && "Unreachable");
    return -1;
}

int learn_coml()
{
    char* p = malloc(10 * sizeof(char));
    while (1) {
        printf(": ");
        fgets(p, 10, stdin);
        if (strlen(p) == 2) {
            if (p[0] == '1' || p[0] == '2' || p[0] == '3') {
                return p[0] - '0';
            }
            if (isdigit(p[0])) {
                printf("[E] Введен неизвестная сложность! Повтор ввода");
                continue;
            }
            if (p[0] == 'q') {
                free(p);
                printf("[E] Выход из программы...");
                return -1;
            }
            printf("[E] Введен неизвестный символ! Повтор ввода");
        } else
            printf("[E] Введен неизвестный символ! Повтор ввода");
    }
    assert(0 && "Unreachable");
    return -1;
}

int learn_settings(int* language, int* comlexity)
{
    int lang_flag, coml_flag;
    print_lang();
    lang_flag = learn_lang();
    if (lang_flag == -1)
        exit(-1);
    else
        *language = lang_flag;
    print_coml();
    coml_flag = learn_coml();
    if (coml_flag == -1)
        exit(-1);
    else
        *comlexity = coml_flag;
    return 0;
}