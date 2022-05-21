#pragma once

#define SIZE_STR 500
#define SIZE_DICTIONARY 300

char** read_dictionary(int cnt);
char* specified_string(char** dict, int language, int complexity, int cnt);
char* user_string(double* time, char* spec_string);
void free_all(char* user_str, int* analyz_print, char** dict);
