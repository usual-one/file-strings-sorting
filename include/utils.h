#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>


int Sum(const char* digits,
        size_t digits_size);

// changes content of `words`
void Sort(char** words,
          size_t words_size); 

void Swap(char *a,
          char *b);

#endif // UTILS_H
