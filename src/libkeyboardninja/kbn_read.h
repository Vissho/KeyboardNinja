#ifndef _KBN_READ_
#define _KBN_READ_

#define SIZE_STR 150

char** read_dictionary(int* cnt);
char* find_string(char** dict, int language, int complexity, int cnt);
char* user_string(double* time, char* spec_string);

#endif // _KBN_READ_