#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types_split.h"


void ConvertToDigits(string *numbers,
                     size_t numbers_size,
                     char **digits,
                     size_t *digits_size) {
    assert(numbers != NULL);
    for (size_t i = 0; i < numbers_size; i++) {
        assert(numbers[i]);
    }

    // ----- Counting digits array size -----
    *digits_size = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                (*digits_size)++;
            }
        }
    }
    // -----

    // ----- Filling digits array -----
    *digits = (char *) malloc((*digits_size) * sizeof(char));
    int digits_counter = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                (*digits)[digits_counter] = numbers[i][j] - '0';
                digits_counter++;
            }
        }
    }
    // -----
}

void PickTypes(string *lines,
               size_t lines_size,
               string **words,
               size_t *words_size,
               string **numbers,
               size_t *numbers_size) {
    assert(lines != NULL);
    for (size_t i = 0; i < lines_size; i++) {
        assert(lines[i] != NULL);
    }

    *words = (string *) malloc(lines_size * sizeof(string));
    *numbers = (string *) malloc(lines_size * sizeof(string));
    *words_size = 0;
    *numbers_size = 0;

    char number_flag = 1;
    for (size_t i = 0; i < lines_size; i++) {
        for (size_t j = 0; j < strlen(lines[i]); j++) {
            if (!isdigit(lines[i][j]) 
                    && lines[i][j] != '.' 
                    && lines[i][j] != '-') {
                number_flag = 0;
                break;
            }
        }
        if (number_flag) {
            (*numbers)[*numbers_size] = (string) malloc((strlen(lines[i]) + 1) * sizeof(char));
            strcpy((*numbers)[*numbers_size], lines[i]);
            (*numbers_size)++; 
        } else {
            (*words)[*words_size] = (string) malloc((strlen(lines[i]) + 1) * sizeof(char));
            strcpy((*words)[*words_size], lines[i]);
            (*words_size)++;
        }
        number_flag = 1;
    }
}

void Split(const string line,
           char delimeter,
           string **arr,
           size_t *arr_size) {
    assert(line != NULL);

    // ----- Counting size of split_lines array -----
    *arr_size = 0;
    char prev = delimeter;
    for (size_t i = 0; i < strlen(line); i++) {
        if (line[i] != delimeter && prev == delimeter) {
            (*arr_size)++;
        }
        prev = line[i];
    }
    // -----

    // ----- Splitting line and copying it to split_lines array -----
    *arr = (string *) malloc((*arr_size) * sizeof(string));
    
    string line_copy = (string) malloc((strlen(line) + 1) * sizeof(char));
    strcpy(line_copy, line);

    string delimeter_string = (string) malloc(2 * sizeof(char));
    delimeter_string[0] = delimeter;
    delimeter_string[1] = '\0';
    string piece = strtok(line_copy, delimeter_string);

    int lines_counter = 0;
    while (piece != NULL) {
        (*arr)[lines_counter] = (string) malloc((strlen(piece) + 1) * sizeof(char));
        strcpy((*arr)[lines_counter], piece);
        piece = strtok(NULL, delimeter_string);
        lines_counter++;
    }
    free(line_copy);
    free(delimeter_string);
    // -----
}

int SplitByType(const string line,
                string **words,
                size_t *words_size,
                char **digits,
                size_t *digits_size) {
    assert(line != NULL);

    string *split_lines = NULL;
    size_t split_lines_size;
    Split(line, ' ', &split_lines, &split_lines_size);

    string *numbers;
    size_t numbers_size;
    PickTypes(split_lines, split_lines_size, words, words_size, &numbers, &numbers_size);
    for (size_t i = 0; i < split_lines_size; i++) {
        free(split_lines[i]);
    }
    free(split_lines);

    if (!ValidateTypes(*words, *words_size, numbers, numbers_size)) {
        for (size_t i = 0; i < numbers_size; i++) {
            free(numbers[i]);
        }
        free(numbers);
        for (size_t i = 0; i < (*words_size); i++) {
            free((*words)[i]);
        }
        free(*words);
        return -1;
    }

    ConvertToDigits(numbers, numbers_size, digits, digits_size);
    for (size_t i = 0; i < numbers_size; i++) {
        free(numbers[i]);
    }
    free(numbers);
    return 0;
}

char ValidateTypes(string *words,
                   size_t words_size,
                   string *numbers,
                   size_t numbers_size) {
    assert(words != NULL);
    for (size_t i = 0; i < words_size; i++) {
        assert(words[i] != NULL);
    }
    assert(numbers != NULL);
    for (size_t i = 0; i < numbers_size; i++) {
        assert(numbers[i] != NULL);
    }

    for (size_t i = 0; i < words_size; i++) {
        for (size_t j = 0; j < strlen(words[i]); j++) {
            if (!isalpha(words[i][j]) 
                && !isdigit(words[i][j]) 
                && words[i][j] != '-') {
                return 0;
            }
        }
    }

    char dot_flag = 0;
    char zero_flag = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                if (numbers[i][j] == '0' && j && zero_flag) {
                    return 0;
                }
            } else {
                if ((numbers[i][j] == '-' && j)
                    || (numbers[i][j] == '.' && (!j || dot_flag))) {
                    return 0;
                }
                if (numbers[i][j] != '-' && numbers[i][j] != '.') {
                    return 0;
                }
            }
            if (numbers[i][j] == '.') {
                dot_flag = 1;
                zero_flag = 0;
            } else if (numbers[i][j] == '0' && !j) {
                zero_flag = 1;
            } else {
                zero_flag = 0;
            }
        }
        dot_flag = 0;
        zero_flag = 0;
    }
    return 1;
}
