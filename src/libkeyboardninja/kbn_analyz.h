#pragma once
#include <stddef.h>

struct rank {
    char* key;
    int value;
};

enum {
    NOT_CONFIDENT = 50,
    MASTERED = 100,
    BEGINNER = 150,
    DEFAULT_USER = 200,
    CONFIDENT_USER = 250,
    ADVANCED_USER = 300,
    TYPER = 350,
    EXP_TYPER = 400,
    TYPE_MACHINE = 450,
    ROBOT = 500,
    CYBERPSICHO = 550
};

#define RU_UPPER_CASE -48
#define RU_LOWER_CASE -47

int* analyz(char* spec_string, char* user_string, int* size);
float symbols_in_min(char* user_str, float time);
void print_rate(float sym_in_sec);
int correct_str(int* arr, size_t len);
void incorrect_output(
        char* user_str,
        char* spec_string,
        int* analyz_print,
        int cnt,
        double time);
void correct_output(double time, char* user_str);