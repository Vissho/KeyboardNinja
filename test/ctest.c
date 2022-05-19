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
