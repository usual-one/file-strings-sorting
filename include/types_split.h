#ifndef TYPES_SPLIT_H
#define TYPES_SPLIT_H

#include <stddef.h>

#include "types.h"


// `digits` will be allocated and must be freed
void ConvertToDigits(string *numbers,
                     size_t numbers_size,
                     char **digits,
                     size_t *digits_size);

// `words` and `numbers` will be allocated and must be freed
// `words` and `numbers` elements will be allocated and must be freed
void PickTypes(string *lines, 
               size_t lines_size, 
               string **words,
               size_t *words_size,
               string **numbers,
               size_t *numbers_size);

// `split_lines` will be allocated and must be freed
// `split_lines` elements will be allocated and must be freed
void Split(const string line, 
           char delimeter,
           string **arr, 
           size_t *arr_size);

// `words` and `digits` will be allocated and must be freed
// `words` elements will be allocated and must be freed
int SplitByType(const string line,
                string **words,
                size_t *words_size,
                char **digits,
                size_t *digits_size);

char ValidateTypes(string *words,
                   size_t words_size,
                   string *numbers,
                   size_t numbers_size);

#endif // TYPES_SPLIT_H
