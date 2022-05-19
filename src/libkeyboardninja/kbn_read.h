#ifndef _KBN_READ_
#define _KBN_READ_

#define SIZE_STR 500
#define SIZE_DICTIONARY 300

char** read_dictionary(int cnt);
char* find_string(char** dict, int language, int complexity, int cnt);
char* user_string(double* time, char* spec_string);
int free_all(char* user_str, int* analyz_print, char** dict);

#endif // _KBN_READ_