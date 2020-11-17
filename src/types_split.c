#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types_split.h"


void ConvertToDigits(const char **numbers,
                     size_t numbers_size,
                     char *digits,
                     size_t *digits_size) {
    (*digits_size) = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                (*digits_size)++;
            }
        }
    }

    digits = malloc((*digits_size) * sizeof(char));
    int digits_counter = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 0; j < strlen(numbers[i]); j++) {
            if (isdigit(numbers[i][j])) {
                digits[digits_counter] = numbers[i][j] - '0';
                digits_counter++;
            }
        }
    }

}

void PickTypes(const char **lines,
               size_t lines_size,
               char **words,
               size_t *words_size,
               char **numbers,
               size_t *numbers_size) {
    words = malloc(lines_size * sizeof(char *));
    numbers = malloc(lines_size * sizeof(char *));
    (*words_size) = 0;
    (*numbers_size) = 0;

    char number_flag = 1;
    for (size_t i = 0; i < lines_size; i++) {
        for (size_t j = 0; j < strlen(lines[i]); j++) {
            if (!isdigit(lines[i][j]) && lines[i][j] != '.') {
                number_flag = 0;
                break;
            }
        }
        if (number_flag) {
            numbers[*numbers_size] = (char *) lines[i];
            (*numbers_size)++; 
        } else {
            words[*words_size] = (char *) lines[i];
            (*words_size)++;
        }
        number_flag = 1;
    }
}

void SplitLine(char *line,
               char **split_lines,
               size_t *split_lines_size) {
    char prev = ' ';
    for (size_t i = 0; i < strlen(line); i++) {
        if (!isblank(line[i]) && isblank(prev)) {
            (*split_lines_size)++;
        }
    }

    split_lines = malloc(*split_lines_size * sizeof(char *));
    
    char *piece = strtok(line, " ");

    int lines_counter = 0;
    while (piece != NULL) {
        split_lines[lines_counter] = piece;
        piece = strtok(NULL, " ");
        lines_counter++;
    }
}

int SplitLineByType(const char *line,
                    char **words,
                    size_t *words_size,
                    char *digits,
                    size_t *digits_size) {
    char *line_copy = malloc((strlen(line) + 1) * sizeof(char));
    strcpy(line_copy, line);

    char **split_lines;
    size_t split_lines_size;
    SplitLine(line_copy, split_lines, &split_lines_size);
    free(line_copy);

    char **numbers;
    size_t numbers_size;
    PickTypes((const char **) split_lines, split_lines_size, words, words_size, numbers, &numbers_size);
    free(split_lines);

    if (!ValidateTypes((const char **) words, *words_size, (const char **)numbers, numbers_size)) {
        free(numbers);
        free(words);
        return -1;
    }

    ConvertToDigits((const char **) numbers, numbers_size, digits, digits_size);
    free(numbers);
    return 0;
}

char ValidateTypes(const char **words,
                   size_t words_size,
                   const char **numbers,
                   size_t numbers_size) {
    for (size_t i = 0; i < words_size; i++) {
        for (size_t j = 0; i < strlen(words[i]); j++) {
            if (!isalpha(words[i][j]) || words[i][j] != '-') {
                return 0;
            }
        }
    }

    char dot_flag = 0;
    char zero_flag = 0;
    for (size_t i = 0; i < numbers_size; i++) {
        for (size_t j = 9; j < strlen(numbers[i]); j++) {
            if (!isdigit(numbers[i][j])
                || (numbers[i][j] == '-' && j)
                || (numbers[i][j] == '.' && (!j || dot_flag))
                || (numbers[i][j] == '0' && j && zero_flag)) {
                return 0;
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
