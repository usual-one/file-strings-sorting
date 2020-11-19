#ifndef CONVERSION_H
#define CONVERSION_H

#include <stddef.h>

#include "types.h"


// `line_size` includes null-terminating char
int ConvertFile(const string dest_path,
                const string src_path,
                int line_size);

// `converted_line` will be allocated and must be freed
int ConvertLine(const string line, 
                string *converted_line);

// returned value will be allocated and must be freed
string CreateConvertedLine(const string *words,
                           size_t words_size,
                           int digits_sum);

// returned value will be allocated and must be freed
string ToString(int number);

#endif // CONVERSION_H
