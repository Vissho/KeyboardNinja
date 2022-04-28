#include <libkeyboardninja/kbn_analyz.h>
#include <stdio.h>
#include <stdlib.h>

int* analyz(char* spec_string, char* user_string, int* size)
{
    int i = 0, cnt = 1;
    while(user_string[i] != '\0'){
        i++;
        cnt++;
    }
    int* analyz = (int*)malloc(cnt * sizeof(int));
    i = 0;
    while(spec_string[i] != '\n'){
        if(user_string[i] == spec_string[i]){
            analyz[i] = 1;
        }else{
            analyz[i] = 0;
        }
        i++;
    }
    while(i < cnt){
        analyz[i] = 0;
        i++;
    }
    *size = i - 1;
    return analyz;
}
