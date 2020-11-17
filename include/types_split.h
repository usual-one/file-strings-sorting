#ifndef TYPES_SPLIT_H
#define TYPES_SPLIT_H

#include <stddef.h>


// `digits` will be allocated and must be freed
void ConvertToDigits(const char **numbers,
                     size_t numbers_size,
                     char *digits,
                     size_t *digits_size);

// `words` and `numbers` will be allocated and must be freed
void PickTypes(const char **lines, 
               size_t lines_size, 
               char **words,
               size_t *words_size,
               char **numbers,
               size_t *numbers_size);

// changes `line` content (spaces -> '\0')
// `split_lines` will be allocated and must be freed
// `split_lines` will contain ptrs to `line` parts
void SplitLine(char *line, 
               char **split_lines, 
               size_t *split_lines_size);

// `words` and `digits` will be allocated and must be freed
int SplitLineByType(const char *line,
                    char **words,
                    size_t *words_size,
                    char *digits,
                    size_t *digits_size);

char ValidateTypes(const char **words,
                   size_t words_size,
                   const char **numbers,
                   size_t numbers_size);

#endif // TYPES_SPLIT_H
