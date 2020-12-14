#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stddef.h>

#include "../../include/types.h"


int TestUtils();

int TestSum(const char *digits,
            size_t digits_size,
            int assumed_output);

int TestSort(const string *arr,
             size_t arr_size,
             const string *assumed_output);

#endif // TEST_UTILS_H
