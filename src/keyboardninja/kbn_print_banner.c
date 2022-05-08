#include <keyboardninja/kbn_print_banner.h>

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

char get()
{
    char c;
    scanf("%c", &c);
    return c;
}

int learn_lang()
{
    char p;
    int c = 0;
    while (1) {
        printf(": ");
        scanf(" %c", &p);
        if (isdigit(p)) {
            c = p - '0';
            if (c != 1 && c != 2) {
                printf("[E] Введен неизвестный язык! Повтор ввода");
                continue;
            } else
                return c;
        } else if (p == 'q') {
            printf("[E] Выход из программы...");
            return -1;
        } else {
            printf("[E] Введен неизвестный символ! Повтор ввода");
            continue;
        }
    }
    printf("[E] Выход из программы...");
    return -1;
}

int learn_coml()
{
    char p;
    int c = 0;
    while (1) {
        printf(": ");
        scanf(" %c", &p);
        if (isdigit(p)) {
            c = p - '0';
            if (c != 1 && c != 2 && c != 3) {
                printf("[E] Введен неизвестная сложность! Повтор ввода");
                continue;
            } else
                return c;
        } else if (p == 'q') {
            printf("[E] Выход из программы...");
            return -1;
        } else {
            printf("[E] Введен неизвестный символ! Повтор ввода");
            continue;
        }
    }
    printf("[E] Выход из программы...");
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