#include <assert.h>
#include <stdlib.h>
#include <strings.h>

#include "../include/utils.h"


int Sum(const char *digits,
        size_t digits_size) {
    assert(digits != NULL);

    int sum = 0;
    for (size_t i = 0; i < digits_size; i++) {
        sum += digits[i];
    }
    return sum;
}

void Sort(string **arr,
          size_t arr_size) {
   assert(*arr != NULL);
   for (size_t i = 0; i < arr_size; i++) {
       assert((*arr)[i] != NULL);
   }

   for (size_t i = 0; i < arr_size; i++) {
       for (size_t j = 0; j < arr_size - 1 - i; j++) {
           if (strcasecmp((*arr)[j], (*arr)[j + 1]) > 0) {
               Swap((*arr) + j, (*arr) + j + 1);
           }
       }
   } 
}

void Swap(string *a,
          string *b) {
    assert(*a != NULL);
    assert(*b != NULL);

    char *temp = *a;
    (*a) = *b;
    (*b) = temp;
}
