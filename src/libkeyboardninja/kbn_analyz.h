#ifndef _KBN_ANALYZ_
#define _KBN_ANALYZ_
#include <stdio.h>

int* analyz(char* spec_string, char* user_string, int* size);
float symbols_in_min(char* user_str, float time, int lang);
void print_rate(float sym_in_sec);
int correct_str(int* arr, size_t len);
void incorrect_output(char* user_str, char* spec_string, int* analyz_print, int cnt);
void correct_output(double time, char* user_str, int lang);
void print_less_cnt_sym();
//

#endif // _KBN_ANALYZ_