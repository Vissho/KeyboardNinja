#pragma once
#include <stddef.h>

#define RU_UPPER_CASE -48
#define RU_LOWER_CASE -47

struct rank {
    char* key;
    int value;
};

int* analyz(char* spec_string, char* user_string, int* size);
float symbols_in_min(char* user_str, float time);
int calculate_rate(float sym_in_min);
int correct_str(int* arr, size_t len);
void incorrect_output(
        char* user_str,
        char* spec_string,
        int* analyz_print,
        int cnt,
        double time);
void correct_output(double time, char* user_str);