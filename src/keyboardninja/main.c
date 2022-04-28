#include <stdio.h>
#include <libkeyboardninja/kbn_read.h>

int main()
{
    int cnt, i;
    //double time;
    char** dict = read_dictionary(&cnt);
    printf("keyboardninja %d\n", cnt);
    for(i = 0; i < cnt; i++){
        printf("%s", dict[i]);
    }
	return 0;
}
