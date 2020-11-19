#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

#include "types.h"


int Sum(const char *digits,
        size_t digits_size);

// changes content of `words`
void Sort(string **arr,
          size_t arr_size); 

void Swap(string *a,
          string *b);

#endif // UTILS_H
