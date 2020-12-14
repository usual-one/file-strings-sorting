#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/test_types_split.h"
#include "../include/test_global.h"
#include "../../include/types_split.h"


int TestTypesSplit() {
    int result = 1;

    // ----- TestConvertToDigits -----
    string convert_to_digits_numbers1[] = {};
    string convert_to_digits_numbers2[] = {"1", "2"};
    string convert_to_digits_numbers3[] = {"12", "345"};
    string convert_to_digits_numbers4[] = {"12.3", "4.5"};
    string convert_to_digits_numbers5[] = {"-12.3", "-4.5"};

    size_t convert_to_digits_numbers1_size = 0;
    size_t convert_to_digits_numbers2_size = 2;
    size_t convert_to_digits_numbers3_size = 2;
    size_t convert_to_digits_numbers4_size = 2;
    size_t convert_to_digits_numbers5_size = 2;

    char convert_to_digits_assumed_digits1[] = {};
    char convert_to_digits_assumed_digits2[] = {1, 2};
    char convert_to_digits_assumed_digits3[] = {1, 2, 3, 4, 5};
    char convert_to_digits_assumed_digits4[] = {1, 2, 3, 4, 5};
    char convert_to_digits_assumed_digits5[] = {1, 2, 3, 4, 5};

    size_t convert_to_digits_assumed_digits1_size = 0;
    size_t convert_to_digits_assumed_digits2_size = 2;
    size_t convert_to_digits_assumed_digits3_size = 5;
    size_t convert_to_digits_assumed_digits4_size = 5;
    size_t convert_to_digits_assumed_digits5_size = 5;

    if (!TestConvertToDigits(convert_to_digits_numbers1, convert_to_digits_numbers1_size, 
                convert_to_digits_assumed_digits1, convert_to_digits_assumed_digits1_size)) {
        puts("FAIL: types_split: ConverToDigits() | input 1");
        result = 0;
    }
    if (!TestConvertToDigits(convert_to_digits_numbers2, convert_to_digits_numbers2_size, 
                convert_to_digits_assumed_digits2, convert_to_digits_assumed_digits2_size)) {
        puts("FAIL: types_split: ConverToDigits() | input 2");
        result = 0;
    }
    if (!TestConvertToDigits(convert_to_digits_numbers3, convert_to_digits_numbers3_size, 
                convert_to_digits_assumed_digits3, convert_to_digits_assumed_digits3_size)) {
        puts("FAIL: types_split: ConverToDigits() | input 3");
        result = 0;
    }
    if (!TestConvertToDigits(convert_to_digits_numbers4, convert_to_digits_numbers4_size, 
                convert_to_digits_assumed_digits4, convert_to_digits_assumed_digits4_size)) {
        puts("FAIL: types_split: ConverToDigits() | input 4");
        result = 0;
    }
    if (!TestConvertToDigits(convert_to_digits_numbers5, convert_to_digits_numbers5_size, 
                convert_to_digits_assumed_digits5, convert_to_digits_assumed_digits5_size)) {
        puts("FAIL: types_split: ConverToDigits() | input 5");
        result = 0;
    }
    // -----

    // ----- TestPickTypes -----
    string lines1[] = {};
    string lines2[] = {"a", "b"};
    string lines3[] = {"1.32", "-5"};
    string lines4[] = {"a", "-4", "b", "1.2"};

    size_t lines1_size = 0;
    size_t lines2_size = 2;
    size_t lines3_size = 2;
    size_t lines4_size = 4;

    string pick_types_assumed_words1[] = {};
    string pick_types_assumed_words2[] = {"a", "b"};
    string pick_types_assumed_words3[] = {};
    string pick_types_assumed_words4[] = {"a", "b"};

    size_t pick_types_assumed_words1_size = 0;
    size_t pick_types_assumed_words2_size = 2;
    size_t pick_types_assumed_words3_size = 0;
    size_t pick_types_assumed_words4_size = 2;

    string assumed_numbers1[] = {};
    string assumed_numbers2[] = {};
    string assumed_numbers3[] = {"1.32", "-5"};
    string assumed_numbers4[] = {"-4", "1.2"};

    size_t assumed_numbers1_size = 0;
    size_t assumed_numbers2_size = 0;
    size_t assumed_numbers3_size = 2;
    size_t assumed_numbers4_size = 2;

    if (!TestPickTypes(lines1, lines1_size, pick_types_assumed_words1, 
                pick_types_assumed_words1_size, assumed_numbers1, assumed_numbers1_size)) {
        puts("FAIL: types_split: PickTypes() | input 1");
        result = 0;
    }
    if (!TestPickTypes(lines2, lines2_size, pick_types_assumed_words2, 
                pick_types_assumed_words2_size, assumed_numbers2, assumed_numbers2_size)) {
        puts("FAIL: types_split: PickTypes() | input 2");
        result = 0;
    }
    if (!TestPickTypes(lines3, lines3_size, pick_types_assumed_words3, 
                pick_types_assumed_words3_size, assumed_numbers3, assumed_numbers3_size)) {
        puts("FAIL: types_split: PickTypes() | input 3");
        result = 0;
    }
    if (!TestPickTypes(lines4, lines4_size, pick_types_assumed_words4, 
                pick_types_assumed_words4_size, assumed_numbers4, assumed_numbers4_size)) {
        puts("FAIL: types_split: PickTypes() | input 4");
        result = 0;
    }
    // -----

    // ----- TestSplit -----
    string split_line1 = "";
    string split_line2 = "qwerty";
    string split_line3 = "qwe rty uio";
    string split_line4 = "qwe    rty   uio";
    string split_line5 = "qwe,rty,uio";

    char delimeter1 = ' ';
    char delimeter2 = ' ';
    char delimeter3 = ' ';
    char delimeter4 = ' ';
    char delimeter5 = ',';

    string assumed_arr1[] = {};
    string assumed_arr2[] = {"qwerty"};
    string assumed_arr3[] = {"qwe", "rty", "uio"};
    string assumed_arr4[] = {"qwe", "rty", "uio"};
    string assumed_arr5[] = {"qwe", "rty", "uio"};

    size_t assumed_arr1_size = 0;
    size_t assumed_arr2_size = 1;
    size_t assumed_arr3_size = 3;
    size_t assumed_arr4_size = 3;
    size_t assumed_arr5_size = 3;

    if (!TestSplit(split_line1, delimeter1, assumed_arr1, assumed_arr1_size)) {
        puts("FAIL: types_split: Split() | input 1");
        result = 0;
    }
    if (!TestSplit(split_line2, delimeter2, assumed_arr2, assumed_arr2_size)) {
        puts("FAIL: types_split: Split() | input 2");
        result = 0;
    }
    if (!TestSplit(split_line3, delimeter3, assumed_arr3, assumed_arr3_size)) {
        puts("FAIL: types_split: Split() | input 3");
        result = 0;
    }
    if (!TestSplit(split_line4, delimeter4, assumed_arr4, assumed_arr4_size)) {
        puts("FAIL: types_split: Split() | input 4");
        result = 0;
    }
    if (!TestSplit(split_line5, delimeter5, assumed_arr5, assumed_arr5_size)) {
        puts("FAIL: types_split: Split() | input 5");
        result = 0;
    }
    // -----

    // ----- TestSplitByType -----
    string split_by_type_line1 = "";
    string split_by_type_line2 = "a b";
    string split_by_type_line3 = "a -1.2 b1 4";
    string split_by_type_line4 = "10.9 -4";

    string split_by_type_assumed_words1[] = {};
    string split_by_type_assumed_words2[] = {"a", "b"};
    string split_by_type_assumed_words3[] = {"a", "b1"};
    string split_by_type_assumed_words4[] = {};

    size_t split_by_type_assumed_words1_size = 0;
    size_t split_by_type_assumed_words2_size = 2;
    size_t split_by_type_assumed_words3_size = 2;
    size_t split_by_type_assumed_words4_size = 0;

    char split_by_type_assumed_digits1[] = {};
    char split_by_type_assumed_digits2[] = {};
    char split_by_type_assumed_digits3[] = {1, 2, 4};
    char split_by_type_assumed_digits4[] = {1, 0, 9, 4};

    size_t split_by_type_assumed_digits1_size = 0;
    size_t split_by_type_assumed_digits2_size = 0;
    size_t split_by_type_assumed_digits3_size = 3;
    size_t split_by_type_assumed_digits4_size = 4;

    if (!TestSplitByType(split_by_type_line1, split_by_type_assumed_words1,
               split_by_type_assumed_words1_size, split_by_type_assumed_digits1,
               split_by_type_assumed_digits1_size)) {
        puts("FAIL: types_split: SplitByType() | input 1");
        result = 0;
    } 
    if (!TestSplitByType(split_by_type_line2, split_by_type_assumed_words2,
               split_by_type_assumed_words2_size, split_by_type_assumed_digits2,
               split_by_type_assumed_digits2_size)) {
        puts("FAIL: types_split: SplitByType() | input 2");
        result = 0;
    } 
    if (!TestSplitByType(split_by_type_line3, split_by_type_assumed_words3,
               split_by_type_assumed_words3_size, split_by_type_assumed_digits3,
               split_by_type_assumed_digits3_size)) {
        puts("FAIL: types_split: SplitByType() | input 3");
        result = 0;
    } 
    if (!TestSplitByType(split_by_type_line4, split_by_type_assumed_words4,
               split_by_type_assumed_words4_size, split_by_type_assumed_digits4,
               split_by_type_assumed_digits4_size)) {
        puts("FAIL: types_split: SplitByType() | input 4");
        result = 0;
    } 
    // -----

    // ----- TestValidateTypes -----
    string words1[] = {};
    string words2[] = {"a", "b"};
    string words3[] = {"a", "b"};
    string words4[] = {"a2", "a-b"};
    string words5[] = {"a+q"};
    string words6[] = {"a+q"};

    size_t words1_size = 0;
    size_t words2_size = 2;
    size_t words3_size = 2;
    size_t words4_size = 2;
    size_t words5_size = 1;
    size_t words6_size = 1;

    string validate_types_numbers1[] = {};
    string validate_types_numbers2[] = {"1.2", "-2"};
    string validate_types_numbers3[] = {"1..3"};
    string validate_types_numbers4[] = {"9", "10"};
    string validate_types_numbers5[] = {"1.98", "1"};
    string validate_types_numbers6[] = {"-2-2", "4"};

    size_t validate_types_numbers1_size = 0;
    size_t validate_types_numbers2_size = 2;
    size_t validate_types_numbers3_size = 1;
    size_t validate_types_numbers4_size = 2;
    size_t validate_types_numbers5_size = 2;
    size_t validate_types_numbers6_size = 2;

    char assumed_output1 = 1;
    char assumed_output2 = 1;
    char assumed_output3 = 0;
    char assumed_output4 = 1;
    char assumed_output5 = 0;
    char assumed_output6 = 0;

    if (!TestValidateTypes(words1, words1_size, validate_types_numbers1,
                validate_types_numbers1_size, assumed_output1)) {
        puts("FAIL: types_split: ValidateTypes() | input 1");
        result = 0;
    }
    if (!TestValidateTypes(words2, words2_size, validate_types_numbers2,
                validate_types_numbers2_size, assumed_output2)) {
        puts("FAIL: types_split: ValidateTypes() | input 2");
        result = 0;
    }
    if (!TestValidateTypes(words3, words3_size, validate_types_numbers3,
                validate_types_numbers3_size, assumed_output3)) {
        puts("FAIL: types_split: ValidateTypes() | input 3");
        result = 0;
    }
    if (!TestValidateTypes(words4, words4_size, validate_types_numbers4,
                validate_types_numbers4_size, assumed_output4)) {
        puts("FAIL: types_split: ValidateTypes() | input 4");
        result = 0;
    }
    if (!TestValidateTypes(words5, words5_size, validate_types_numbers5,
                validate_types_numbers5_size, assumed_output5)) {
        puts("FAIL: types_split: ValidateTypes() | input 5");
        result = 0;
    }
    if (!TestValidateTypes(words6, words6_size, validate_types_numbers6,
                validate_types_numbers6_size, assumed_output6)) {
        puts("FAIL: types_split: ValidateTypes() | input 6");
        result = 0;
    }
    // -----

    return result;
}

int TestConvertToDigits(const string *numbers,
                        size_t numbers_size,
                        const char *assumed_digits,
                        size_t assumed_digits_size) {
    TESTS_RUN++;
    char *digits;
    size_t digits_size;

    ConvertToDigits((string *)numbers, numbers_size, &digits, &digits_size);

    int result = 1;

    if (digits_size != assumed_digits_size) {
        result = 0;
    }
    for (size_t i = 0; i < digits_size; i++) {
        if (assumed_digits[i] != digits[i]) {
            result = 0;
            break;
        }
    }

    free(digits);

    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}

int TestPickTypes(const string *lines,
                  size_t lines_size,
                  const string *assumed_words,
                  size_t assumed_words_size,
                  const string *assumed_numbers,
                  size_t assumed_numbers_size) {
    TESTS_RUN++;
    string *words;
    size_t words_size;
    string *numbers;
    size_t numbers_size;
    
    PickTypes((string *)lines, lines_size, &words, &words_size, &numbers, &numbers_size);

    int result = 1;
    
    if (words_size != assumed_words_size ||
        numbers_size != assumed_numbers_size) {
        result = 0;
    }
    for (size_t i = 0; i < words_size; i++) {
        if (strcmp(words[i], assumed_words[i])) {
            result = 0;
            break;
        }
    }
    for (size_t i = 0; i < numbers_size; i++) {
        if (strcmp(numbers[i], assumed_numbers[i])) {
            result = 0;
            break;
        }
    }

    for (size_t i = 0; i < words_size; i++) {
        free(words[i]);
    }
    free(words);
    for (size_t i = 0; i < numbers_size; i++) {
        free(numbers[i]);
    }
    free(numbers);

    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}

int TestSplit(const string line,
              char delimeter,
              const string *assumed_arr,
              size_t assumed_arr_size) {
    TESTS_RUN++;
    string *arr;
    size_t arr_size;

    Split(line, delimeter, &arr, &arr_size);

    int result = 1;

    if (arr_size != assumed_arr_size) {
        result = 0;
    }
    for (size_t i = 0; i < arr_size; i++) {
        if (strcmp(arr[i], assumed_arr[i])) {
            break;
            result = 0;
        }
    }

    for (size_t i = 0; i < arr_size; i++) {
        free(arr[i]);
    }
    free(arr);

    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}

int TestSplitByType(const string line,
                    const string *assumed_words,
                    size_t assumed_words_size,
                    const char *assumed_digits,
                    size_t assumed_digits_size) {
    TESTS_RUN++;
    string *words;
    size_t words_size;
    char *digits;
    size_t digits_size;

    SplitByType(line, &words, &words_size, &digits, &digits_size);

    int result = 1;

    if (words_size != assumed_words_size ||
        digits_size != assumed_digits_size) {
        result = 0;
    }
    for (size_t i = 0; i < words_size; i++) {
        if (strcmp(words[i], assumed_words[i])) {
            result = 0;
            break;
        }
    }
    for (size_t i = 0; i < digits_size; i++) {
        if (digits[i] != assumed_digits[i]) {
            result = 0;
            break;
        }
    }

    for (size_t i = 0; i < words_size; i++) {
        free(words[i]);
    }
    free(words);
    free(digits);

    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}

int TestValidateTypes(const string *words,
                      size_t words_size,
                      const string *numbers,
                      size_t numbers_size,
                      char assumed_output) {
    TESTS_RUN++;

    if (assumed_output != ValidateTypes((string *)words, words_size, (string *)numbers, numbers_size)) {
        TESTS_FAILED++;
        return 0;
    } else {
        TESTS_SUCCEEDED++;
        return 1;
    }
}
