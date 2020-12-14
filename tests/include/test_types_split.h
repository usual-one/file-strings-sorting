#ifndef TEST_TYPES_SPLIT_H
#define TEST_TYPES_SPLIT_H

#include <stddef.h>

#include "../../include/types.h"


int TestTypesSplit();

int TestConvertToDigits(const string *numbers,
                        size_t numbers_size,
                        const char *assumed_digits,
                        size_t assumed_digits_size);

int TestPickTypes(const string *lines,
                  size_t lines_size,
                  const string *assumed_words,
                  size_t assumed_words_size,
                  const string *assumed_numbers,
                  size_t assumed_numbers_size);

int TestSplit(const string line,
              char delimeter,
              const string *assumed_arr,
              size_t assumed_arr_size);

int TestSplitByType(const string line,
                    const string *assumed_words,
                    size_t assumed_words_size,
                    const char *assumed_digits,
                    size_t assumed_digits_size);

int TestValidateTypes(const string *words,
                      size_t wors_size,
                      const string *numbers,
                      size_t numbers_size,
                      char assumed_output);

#endif // TEST_TYPES_SPLIT_H
