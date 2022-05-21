#include <libkeyboardninja/colors_output.h>
#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

static double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

static int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

char** read_dictionary(int cnt)
{
    int i;
    FILE* fp;
    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Программа не смогла найти заданный файл!\n");
        exit(-1);
    }

    char** dict = (char**)malloc(cnt * sizeof(char*));
    for (i = 0; i < cnt; i++) {
        dict[i] = (char*)malloc(SIZE_STR * sizeof(char));
    }

    i = 0;
    while (!feof(fp)) {
        fgets(dict[i], SIZE_STR, fp);
        i++;
    }

    fclose(fp);
    return dict;
}

char* specified_string(char** dict, int language, int complexity, int cnt)
{
    int start = 0, end = 0, lvls = 6;

    if (language == 1) {
        start = cnt / lvls * (language * (complexity - 1));
        end = cnt / lvls * (language * complexity) - 1;
    } else {
        start = cnt / lvls * (language + complexity);
        end = cnt / lvls * (language + complexity + 1) - 1;
    }

    srand(time(NULL));

    return dict[getrand(start, end)];
}

char* user_string(double* time, char* spec_string)
{
    int timercnt = 3;
    printf("\n%s", spec_string);
    printf("%s\n", YELLOW);
    printf("\nНапиши строку выше через\n");
    for (int x = timercnt; x > 0; x--) {
        printf("%d\n", x);
        sleep(1);
    }
    printf("%s", RESET);
    printf("Ввод ---> ");
    char* user_string = (char*)malloc(SIZE_STR * sizeof(char));
    printf(": ");
    double time_user = wtime();
    stdin->_IO_read_ptr = stdin->_IO_read_end;
    fgets(user_string, SIZE_STR, stdin);
    time_user = wtime() - time_user;
    *time = time_user;
    return user_string;
}

void free_all(char* user_str, int* analyz_print, char** dict)
{
    for (int i = 0; i < SIZE_DICTIONARY; i++) {
        free(dict[i]);
    }
    free(dict);
    free(user_str);
    free(analyz_print);
}