#include <ctest.h>
#include <stdio.h>
#include <string.h>

#include <keyboardninja/kbn_print_banner.h>
#include <libkeyboardninja/colors_output.h>
#include <libkeyboardninja/kbn_analyz.h>
#include <libkeyboardninja/kbn_read.h>

CTEST(read_the_dictionary, correctly_reading_the_dictionary)
{
    char** dictionary = read_dictionary(SIZE_DICTIONARY);

    for (int i = 0; i < SIZE_DICTIONARY; i++)
        ASSERT_NOT_NULL(dictionary[i]);
    ASSERT_NOT_NULL(dictionary);

    for (int i = 0; i < SIZE_DICTIONARY; i++)
        free(dictionary[i]);
    free(dictionary);
}

CTEST(search_a_specified_string, correctly_search_a_specified_string)
{
    char** dictionary = read_dictionary(SIZE_DICTIONARY);
    char* spec_string;
    const int max_language = 2, max_complexity = 3;
    for (int i = 1; i <= max_language; i++) {
        for (int j = 1; j <= max_complexity; j++) {
            spec_string = find_string(dictionary, i, j, SIZE_DICTIONARY);
            ASSERT_NOT_NULL(spec_string);
        }
    }

    for (int i = 0; i < SIZE_DICTIONARY; i++)
        free(dictionary[i]);
    free(dictionary);
}

CTEST(full_memory_release, correctly_full_memory_release)
{
    int size = SIZE_DICTIONARY;
    char** dictionary = read_dictionary(SIZE_DICTIONARY);
    char* spec_string = find_string(dictionary, 2, 2, SIZE_DICTIONARY);
    char* user_str = (char*)malloc(SIZE_STR * sizeof(char));
    strcpy(user_str, "Any other text");
    int* analyz_print = analyz(spec_string, user_str, &size);

    int flag = free_all(user_str, analyz_print, dictionary);

    ASSERT_FALSE(flag);
}

CTEST(symbols_in_min, correctly_symbols_in_min)
{
    float expect_sim = 240;
    char* string = "mask on !@#$)^& mask off";
    double time = 6;
    int lang = 2;
    float sim = symbols_in_min(string, time, lang);
    ASSERT_EQUAL(expect_sim, sim);
}

CTEST(canalyz, correctly_correct_analyz)
{
    int size = 1;
    char* str1 = "inputoutput";
    char* str2 = "inputoutput";
    int* expect = malloc(strlen(str1) * sizeof(int));
    for (size_t x = 0; x < strlen(str1); x++)
        expect[x] = 1;
    int* getted = analyz(str1, str2, &size);
    ASSERT_EQUAL(*expect, *getted);
}

CTEST(correct_str, sorrectly_correct_str)
{
    int* arr = malloc(5 * sizeof(int));
    for (int x = 0; x < 5; x++)
        arr[x] = 1;
    int correct_flag = correct_str(arr, 5);
    ASSERT_TRUE(correct_flag);
}