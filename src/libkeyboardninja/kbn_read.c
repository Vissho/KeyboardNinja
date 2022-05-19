#include <libkeyboardninja/colors_output.h>
#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int read_cnt()
{
    int cnt = 0;
    FILE* fp;
    fp = fopen("dictionary.txt", "r");
    while (!feof(fp)) {
        fscanf(fp, "%*[^\n]%*c");
        cnt++;
    }
    fclose(fp);
    return cnt;
}

char** read_dictionary(int cnt)
{
    int i;
    FILE* fp;
    fp = fopen("dictionary.txt", "r");

    char** dict = (char**)malloc(cnt * sizeof(char*));
    for (i = 0; i < cnt; i++) {
        dict[i] = (char*)malloc(SIZE_STR * sizeof(char));
    }

    i = 0;
    int size;
    char check;
    fseek(fp, 0, SEEK_SET);
    while (!feof(fp)) {
        if (i == cnt - 1) {
            fseek(fp, 0, SEEK_CUR);
            fgets(dict[i], SIZE_STR, fp);
            break;
        }
        size = 1;
        for (fread(&check, 1, 1, fp);
             check != '\n' && check != '\0' && !feof(fp);
             fread(&check, 1, 1, fp)) {
            size++;
        }
        fseek(fp, (-1) * (size), SEEK_CUR);
        fread(dict[i], size, 1, fp);
        dict[i][size] = '\0';
        i++;
    }

    fclose(fp);
    return dict;
}

char* find_string(char** dict, int language, int complexity, int cnt)
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

int free_all(char* user_str, int* analyz_print, char** dict)
{
    int flag = 0;
    for (int i = 0; i < SIZE_DICTIONARY; i++) {
        free(dict[i]);
        if ((dict[i]) == NULL)
            flag = -1;
    }
    free(dict);
    free(user_str);
    free(analyz_print);
    if (dict == NULL || user_str == NULL || analyz_print == NULL)
        flag = -1;
    return flag;
}