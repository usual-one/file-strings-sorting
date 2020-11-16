#include "stddef.h"


void ConvertToDigits(const char ** numbers,
                     size_t numbers_size,
                     char* digits,
                     size_t* digits_size);

void PickTypes(const char** lines, 
               size_t lines_size, 
               char** words,
               size_t* words_size,
               char** numbers,
               size_t* numbers_size);

void SplitLine(const char* line, 
               char** split_lines, 
               size_t* split_lines_size, 
               size_t max_split_line_size);

int SplitLineByType(const char* line,
                    char** words,
                    size_t* words_size,
                    char* digits,
                    size_t* digits_size);

char ValidateTypes(const char** words,
                   size_t words_size,
                   const char* digits,
                   size_t* digits_size);

