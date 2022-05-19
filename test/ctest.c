#include <ctest.h>
#include <stdio.h>

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
