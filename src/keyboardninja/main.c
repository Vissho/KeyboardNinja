#include <stdio.h>
#include <libkeyboardninja/kbn_read.h>
#include <libkeyboardninja/kbn_analyz.h>

int main()
{
    int cnt;
    double time;
    char** dict = read_dictionary(&cnt);
    printf("keyboardninja\n");
    char* spec_string = find_string(dict, 2, 1, cnt);
    char* user_str = user_string(&time, spec_string);
    printf("%s - %.2lf\n", user_str, time);
    int* analyz_print = analyz(spec_string, user_str, &cnt);
    for(int i = 0; i < cnt; i++){
        if(analyz_print[i] == 1){
            printf("\033[32m%c", user_str[i]);
        }else{
            printf("\033[31m%c", user_str[i]);
        }
    }
    printf("\n");
	return 0;
}
