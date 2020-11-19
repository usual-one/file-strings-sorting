#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/conversion.h"
#include "../include/files.h"
#include "../include/types_split.h"
#include "../include/utils.h"


int ConvertFile(const string dest_path,
                const string src_path,
                int line_size) {
    //puts("ConvertFile:0: function started"); //DEBUG
    FILE *read_fd = fopen(src_path, "r");
    if (read_fd == NULL) {
        return -1;
    }
    FILE *write_fd = fopen(dest_path, "w");
    if (write_fd == NULL) {
        fclose(read_fd);
        return -1;
    }
    //puts("ConvertFile:1: files opened"); // DEBUG

    string read_line = NULL;
    string converted_line = NULL;
    while (!feof(read_fd)) {
        if (ReadLine(read_fd, &read_line, line_size) == -1) {
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }
    //    printf("ConvertFile:2:loop: read_line: %s\n", read_line); // DEBUG
        if (ConvertLine(read_line, &converted_line) == -1) {
            free(read_line);
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }
    //    printf("ConvertFile:3:loop: converted_line: %s\n", converted_line); // DEBUG
        if (WriteLine(write_fd, converted_line, !feof(read_fd)) == -1) {
            free(read_line);
            free(converted_line);
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }
    //    puts("ConvertFile:4:loop: line written"); // DEBUG
 
        free(read_line);
        free(converted_line);
    }
    
    fclose(read_fd);
    fclose(write_fd);
    //puts("ConvertFile:5: function finished"); // DEBUG
    return 0;
}

int ConvertLine(const string line,
                string *converted_line) {
    //puts("ConvertLine:0: function started"); // DEBUG
    string *words;
    size_t words_size;
    char* digits;
    size_t digits_size;
    //printf("ConvertLine:1: line: %s\n", line); // DEBUG

    if (SplitByType(line, &words, &words_size, &digits, &digits_size) == -1) {
        return -1;
    }
    for (size_t i = 0; i < words_size; i++) {
    //    printf("ConvertLine:2:loop word: %s\n", words[i]); // DEBUG
    }
    for (size_t i = 0; i < digits_size; i++) {
    //    printf("ConvertLine:3:loop digit: %d\n", digits[i]); // DEBUG
    }

    int digits_sum = Sum(digits, digits_size);
    //printf("ConvertLine:4: digits_sum: %d\n", digits_sum); // DEBUG
    Sort(&words, words_size);
    for (size_t i = 0; i < words_size; i++) {
    //    printf("ConvertLine:5:loop sorted word: %s\n", words[i]); // DEBUG
    }
    *converted_line = CreateConvertedLine((const string *) words, words_size, digits_sum);
    //printf("ConvertLine:6: converted_line: %s\n", *converted_line); // DEBUG

    for (size_t i = 0; i < words_size; i++) {
        free(words[i]);
    }
    free(words);

    //puts("ConvertLine:7: function finished"); // DEBUG
    return 0;
}

string CreateConvertedLine(const string *words,
                           size_t words_size,
                           int digits_sum) {

    size_t line_size = 0;  
    for (size_t i = 0; i < words_size; i++) {
        line_size += strlen(words[i]);
        line_size++; // ' '
    }

    string sum_string;
    if (digits_sum) {
        sum_string = ToString(digits_sum);
        line_size += strlen(sum_string);
    }
    line_size++; // '\0'

    string converted_line = (string) malloc(line_size * sizeof(char));
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

string ToString(int number) {
    int temp_copy = number;
    int number_char_size = 0;

    if (!temp_copy) {
        number_char_size = 1;
    }

    while (temp_copy != 0) {
        temp_copy /= 10;
        number_char_size++;
    }
    string string_number = (string) malloc((number_char_size + 1) * sizeof(char));
    sprintf(string_number, "%d", number);
    return string_number;
}
