#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max) {
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

char** read_dictionary(int* cnt)
{
    int i;
    *cnt = -1;
    FILE* fp;
    fp = fopen("dictionary.txt", "r");

    while(!feof(fp)){
        fscanf(fp, "%*[^\n]%*c");
        (*cnt)++;
    }

    char** dict = (char**)malloc((*cnt) * sizeof(char*));
    for(i = 0; i < *cnt; i++){
        dict[i] = (char*)malloc(SIZE_STR * sizeof(char));
    }

    i = 0;
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){
        fgets(dict[i], SIZE_STR, fp);
        i++;
    }

    fclose(fp);
    return dict;
}

char* find_string(char** dict, int language, int complexity, int cnt)
{
    int start, end;

    if(language == 1){
        start = cnt / 6 * (language * (complexity - 1));
        end = cnt / 6 * (language * complexity) - 1;
    }else{
        start = cnt / 6 * (language + complexity);
        end = cnt / 6 * (language + complexity + 1) - 1;
    }

    srand(time(NULL));

    return dict[getrand(start, end)];
}

char* user_string(double* time, char* spec_string)
{
    printf("Напиши данную строку: %s", spec_string);
    char* user_string = (char*)malloc(SIZE_STR * sizeof(char));
    printf(": ");
    double time_user = wtime();
    scanf("%s", user_string);
    time_user = wtime() - time_user;
    *time = time_user;
    return user_string;
}
