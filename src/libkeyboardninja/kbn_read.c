#include <libkeyboardninja/kbn_read.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_STR 50

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
