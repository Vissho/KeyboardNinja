#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once

void print_banner();
int learn_settings(int* lang, int* complexity);
void print_stat(float words_in_sec, int blots, char* user_str);
char* str_print(int language, int complexity);
int learn_lang();
int learn_coml();
void print_lang();
void print_coml();