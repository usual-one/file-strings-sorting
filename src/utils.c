#include <stdlib.h>
#include <strings.h>

#include "../include/utils.h"


int Sum(const char* digits,
        size_t digits_size) {
    int sum = 0;
    for (size_t i = 0; i < digits_size; i++) {
        sum += digits[i];
    }
    return sum;
}

void Sort(char** words,
          size_t words_size) {
   for (size_t i = 0; i < words_size; i++) {
       for (size_t j = 0; j < words_size - 1 - i; j++) {
           if (strcasecmp(words[j], words[j + 1]) > 0) {
               Swap(words[j], words[j + 1]);
           }
       }
   } 
}

void Swap(char *a,
          char *b) {
    char temp = *a;
    (*a) = *b;
    (*b) = temp;
}
