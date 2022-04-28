#include <stdio.h>
#include <libkeyboardninja/kbn_read.h>

int main()
{
    int cnt;
    double time;
    char** dict = read_dictionary(&cnt);
    printf("keyboardninja\n");
    char* spec_string = find_string(dict, 2, 1, cnt);
    char* user_str = user_string(&time, spec_string);
    printf("%s - %.2lf\n", user_str, time);
	return 0;
}
