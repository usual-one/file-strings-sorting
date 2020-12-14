#ifndef TEST_CONVERSION_H
#define TEST_CONVERSION_H

#include <stddef.h>

#include "../../include/types.h"


int TestConversion();

int TestConvertLine(const string input,
                    const string assumed_output);

int TestCreateConvertedLine(const string *words,
                            size_t words_size,
                            int digits_sum,
                            const string assumed_output);

int TestToString(int number,
                 const string assumed_output);

#endif // TEST_CONVERSION_H
