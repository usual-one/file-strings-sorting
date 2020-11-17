#ifndef CONVERSION_H
#define CONVERSION_H

#include "stddef.h"


// `line_size` includes null-terminating char
int ConvertFile(const char *dest_path,
                const char *src_path,
                int line_size);

// `converted_line` will be allocated and must be freed
int ConvertLine(const char *line, 
                char *converted_line);

// returned value will be allocated and must be freed
char *CreateConvertedLine(const char **words,
                          size_t words_size,
                          int digits_sum);

// returned value will be allocated and must be freed
char *ToString(int number);

#endif // CONVERSION_H
