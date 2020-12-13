#ifndef TEST_TYPES_SPLIT_H
#define TEST_TYPES_SPLIT_H

#include <stddef.h>

#include "../types.h"


int TestTypesSplit();

int TestConvertToDigits(string *numbers,
                        size_t numbers_size,
                        char *assumed_digits,
                        size_t assumed_digits_size);

int TestPickTypes(string *lines,
                  size_t lines_size,
                  string *assumed_words,
                  size_t assumed_words_size,
                  string *assumed_numbers,
                  size_t assumed_numbers_size);

int TestSplit(const string line,
              char delimeter,
              string *assumed_arr,
              size_t assumed_arr_size);

int TestSplitByType(const string line,
                    string *assumed_words,
                    size_t assumed_words_size,
                    char *assumed_digits,
                    size_t assumed_digits_size);

int TestValidateTypes(string *words,
                      size_t wors_size,
                      string *numbers,
                      size_t numbers_size,
                      char assumed_result);

#endif // TEST_TYPES_SPLIT_H
