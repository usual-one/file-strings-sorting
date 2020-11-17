#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/conversion.h"
#include "../include/files.h"
#include "../include/types_split.h"
#include "../include/utils.h"


int ConvertFile(const char *dest_path,
                const char *src_path,
                int line_size) {
    FILE *read_fd = fopen(src_path, "r");
    if (read_fd == NULL) {
        return -1;
    }
    FILE *write_fd = fopen(dest_path, "w");
    if (write_fd == NULL) {
        fclose(read_fd);
        return -1;
    }

    char* read_line;
    char* converted_line;
    while (!feof(read_fd)) {
        if (ReadLine(read_fd, read_line, line_size) == -1) {
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }
        if (ConvertLine(read_line, converted_line) == -1) {
            free(read_line);
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }
        if (WriteLine(write_fd, converted_line) == -1) {
            free(read_line);
            free(converted_line);
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }

        free(read_line);
        free(converted_line);
    }

    fclose(read_fd);
    fclose(write_fd);
    return 0;
}

int ConvertLine(const char *line,
                char *converted_line) {
    char** words;
    size_t words_size;
    char* digits;
    size_t digits_size;

    if (SplitLineByType(line, words, &words_size, digits, &digits_size) == -1) {
        return -1;
    }

    int digits_sum = Sum(digits, digits_size);
    Sort(words, words_size);
    converted_line = CreateConvertedLine((const char **) words, words_size, digits_sum);

    return 0;
}

char *CreateConvertedLine(const char **words,
                          size_t words_size,
                          int digits_sum) {

    size_t line_size = 0;  
    for (size_t i = 0; i < words_size; i++) {
        line_size += strlen(words[i]);
        line_size++; // ' '
    }

    char *sum_string;
    if (digits_sum) {
        sum_string = ToString(digits_sum);
        line_size += strlen(sum_string);
    }
    line_size++; // '\0'

    char *converted_line = malloc(line_size * sizeof(char));
    converted_line[0] = '\0';
    for (size_t i = 0; i < words_size; i++) {
        strcat(converted_line, words[i]);
        strcat(converted_line, " ");
    }
    if (digits_sum) {
        strcat(converted_line, sum_string);
        free(sum_string); 
    }
    
    return converted_line;
}

char *ToString(int number) {
    int temp_copy = number;
    int number_char_size = 0;

    if (!temp_copy) {
        number_char_size = 1;
    }

    while (temp_copy != 0) {
        temp_copy /= 10;
        number_char_size++;
    }
    char *string = malloc((number_char_size + 1) * sizeof(char));
    sprintf(string, "%d", number);
    return string;
}
