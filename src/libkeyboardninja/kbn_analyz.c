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
        if(user_string[i] == -48 || user_string[i] == -47){
            if(user_string[i] == spec_string[i] && user_string[i+1] == spec_string[i+1]){
                analyz[i] = 1;
                i++;
                analyz[i] = 1;
            }else{
                analyz[i] = 0;
                i++;
                analyz[i] = 0;
            }
        }else{
            if(user_string[i] == spec_string[i]){
                analyz[i] = 1;
            }else{
                analyz[i] = 0;
            }
        }
        i++;
    }
    while(i < cnt){
        analyz[i] = 0;
        i++;
    }
    *size = cnt - 1;
    return analyz;
}
