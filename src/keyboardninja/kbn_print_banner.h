#include <stdio.h>
#pragma once

void print_banner();
void learn_settings(int* lang, int* complexity);
void print_stat(float words_in_sec, int blots, char* user_str);
char* str_print(int language, int complexity);
