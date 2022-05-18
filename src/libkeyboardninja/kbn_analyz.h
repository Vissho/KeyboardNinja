#ifndef _KBN_ANALYZ_
#define _KBN_ANALYZ_

#include <stddef.h>

#define RU_UPPER_CASE -48
#define RU_LOWER_CASE -47

int* analyz(char* spec_string, char* user_string, int* size);
float symbols_in_min(char* user_str, float time, int lang);
void print_rate(float sym_in_sec);
int correct_str(int* arr, size_t len);
void incorrect_output(
        char* user_str,
        char* spec_string,
        int* analyz_print,
        int cnt,
        double time,
        int lang);
void correct_output(double time, char* user_str, int lang);
//

#endif // _KBN_ANALYZ_