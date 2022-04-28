#ifndef _KEYBOARDNINJA_
#define _KEYBOARDNINJA_

#define SIZE_STR 50

char** read_dictionary(int* cnt);
char* find_string(char** dict, int language, int complexity, int cnt);
char* user_string(double* time, char* spec_string);

#endif // _KEYBOARDNINJA_