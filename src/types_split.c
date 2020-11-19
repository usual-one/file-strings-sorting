#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types_split.h"


void ConvertToDigits(string *numbers,
                     size_t numbers_size,
                     char **digits,
                     size_t *digits_size) {
    //puts("ConvertToDigits:0: function started"); // DEBUG
    // ----- Counting digits array size -----
    *digits_size = 0;
    for (size_t i = 0; i < numbers_size; i++) {
    //    printf("ConvertToDigits:1:loop number: %s\n", numbers[i]); // DEBUG
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                (*digits_size)++;
            }
        }
    }
    // -----
    //printf("ConvertToDigits:2: digits_size: %lu\n", *digits_size); // DEBUG

    // ----- Filling digits array -----
    *digits = (char *) malloc((*digits_size) * sizeof(char));
    int digits_counter = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                (*digits)[digits_counter] = numbers[i][j] - '0';
    //            printf("ConvertToDigits:3:loop digit: %d\n", (*digits)[digits_counter]); // DEBUG
                digits_counter++;
            }
        }
    }
    // -----
    //puts("ConvertToDigits:4: function finished"); // DEBUG
}

void PickTypes(string *lines,
               size_t lines_size,
               string **words,
               size_t *words_size,
               string **numbers,
               size_t *numbers_size) {
    //puts("PickTypes:0: function started");
    for (size_t i = 0; i < lines_size; i++) {
    //    printf("PickTypes:1:loop line: %s\n", lines[i]);
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
    //        printf("PickTypes:2:loop number: %s\n", (*numbers)[*numbers_size]);
            (*numbers_size)++; 
        } else {
            (*words)[*words_size] = (string) malloc((strlen(lines[i]) + 1) * sizeof(char));
            strcpy((*words)[*words_size], lines[i]);
    //        printf("PickTypes:3:loop word: %s\n", (*words)[*words_size]);
            (*words_size)++;
        }
        number_flag = 1;
    }
    //puts("PickTypes:4: function finished");
}

void Split(const string line,
           char delimeter,
           string **arr,
           size_t *arr_size) {
    //puts("SplitLine:0: function started"); // DEBUG
    //printf("SplitLine:1: line: %s\n", line); // DEBUG

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
    //printf("SplitLine:2: split_lines_size: %lu\n", *split_lines_size); // DEBUG

    // ----- Splitting line and copying it to split_lines array -----
    *arr = (string *) malloc((*arr_size) * sizeof(string));
    
    string line_copy = (string) malloc((strlen(line) + 1) * sizeof(char));
    strcpy(line_copy, line);
    //printf("SplitLine:3: line_copy: %s\n", line_copy); // DEBUG

    string delimeter_string = (string) malloc(2 * sizeof(char));
    delimeter_string[0] = delimeter;
    delimeter_string[1] = '\0';
    string piece = strtok(line_copy, delimeter_string);

    int lines_counter = 0;
    while (piece != NULL) {
    //    printf("SplitLine:4:loop piece: %s\n", piece); // DEBUG
        (*arr)[lines_counter] = (string) malloc((strlen(piece) + 1) * sizeof(char));
        strcpy((*arr)[lines_counter], piece);
    //    printf("SplitLine:5:loop split_line: %s\n", (*split_lines)[lines_counter]); // DEBUG
        piece = strtok(NULL, delimeter_string);
        lines_counter++;
    }
    free(line_copy);
    free(delimeter_string);
    // -----
    //puts("SplitLine:6: function finished"); // DEBUG
}

int SplitByType(const string line,
                string **words,
                size_t *words_size,
                char **digits,
                size_t *digits_size) {
    //puts("SplitLineByType:0: function started"); // DEBUG
    //printf("SplitLineByType:1: line: %s\n", line); // DEBUG

    string *split_lines = NULL;
    size_t split_lines_size;
    Split(line, ' ', &split_lines, &split_lines_size);
    for (size_t i = 0; i < split_lines_size; i++) {
    //    printf("SplitLineByType:2:loop split_line: %s\n", split_lines[i]); // DEBUG
    }

    string *numbers;
    size_t numbers_size;
    PickTypes(split_lines, split_lines_size, words, words_size, &numbers, &numbers_size);
    for (size_t i = 0; i < split_lines_size; i++) {
        free(split_lines[i]);
    }
    free(split_lines);
    for (size_t i = 0; i < (*words_size); i++) {
    //    printf("SplitLineByType:3:loop word: %s\n", (*words)[i]); // DEBUG
    }
    for (size_t i = 0; i < numbers_size; i++) {
    //    printf("SplitLineByType:4:loop number: %s\n", numbers[i]); // DEBUG
    }

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
    //puts("SplitLineByType:5: lines validated"); // DEBUG

    ConvertToDigits(numbers, numbers_size, digits, digits_size);
    for (size_t i = 0; i < numbers_size; i++) {
        free(numbers[i]);
    }
    free(numbers);
    for (size_t i = 0; i < (*digits_size); i++) {
    //    printf("SplitLineByType:6:loop digit: %d\n", (*digits)[i]); // DEBUG
    }
    //puts("SplitLineByType:7: function finished"); // DEBUG
    return 0;
}

char ValidateTypes(string *words,
                   size_t words_size,
                   string *numbers,
                   size_t numbers_size) {
    //puts("ValidateTypes:0: function started"); // DEBUG
    for (size_t i = 0; i < words_size; i++) {
    //    printf("ValidateTypes:1:loop word: %s\n", words[i]); // DEBUG
        for (size_t j = 0; j < strlen(words[i]); j++) {
            if (!isalpha(words[i][j]) && words[i][j] != '-') {
    //            printf("ValidateTypes:2: invalid char: %c\n", words[i][j]); // DEBUG
                return 0;
            }
        }
    }
    //puts("ValidateTypes:3: words validated"); // DEBUG

    char dot_flag = 0;
    char zero_flag = 0;
    for (size_t i = 0; i < numbers_size; i++) {
    //    printf("ValidateTypes:4:loop number: %s\n", numbers[i]); // DEBUG
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                if (numbers[i][j] == '0' && j && zero_flag) {
    //                printf("ValidateTypes:5: invalid char: %c\n", numbers[i][j]); // DEBUG
    //                printf("ValidateTypes:6: j: %lu\n", j); // DEBUG
    //                printf("ValidateTypes:8: zero_flag: %d\n", zero_flag); // DEBUG
                    return 0;
                }
            } else {
                if ((numbers[i][j] == '-' && j)
                    || (numbers[i][j] == '.' && (!j || dot_flag))) {
    //                printf("ValidateTypes:5: invalid char: %c\n", numbers[i][j]); // DEBUG
    //                printf("ValidateTypes:6: j: %lu\n", j); // DEBUG
    //                printf("ValidateTypes:7: dot_flag: %d\n", dot_flag); // DEBUG
                    return 0;
                }
                if (numbers[i][j] != '-' && numbers[i][j] != '.') {
    //                printf("ValidateTypes:5: invalid char: %c\n", numbers[i][j]); // DEBUG
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
    //puts("ValidateTypes:9: numbers validated"); // DEBUG
    //puts("ValidateTypes:10: function finished"); // DEBUG
    return 1;
}
