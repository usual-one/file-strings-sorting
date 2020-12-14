#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/test_conversion.h"
#include "../include/test_global.h"
#include "../../include/conversion.h"

int TestConversion() {
    int result = 1;

    // ----- TestConvertLine -----
    string convert_line_input1 = "";
    string convert_line_input2 = "b d 1 a2";
    string convert_line_input3 = "-12.3 0 1";
    string convert_line_input4 = "j    D A    o";

    string convert_line_assumed_output1 = "";
    string convert_line_assumed_output2 = "a2 b d 1";
    string convert_line_assumed_output3 = "7";
    string convert_line_assumed_output4 = "A D j o";

    if (!TestConvertLine(convert_line_input1, convert_line_assumed_output1)) {
        puts("FAIL: conversion: ConvertLine() | input 1");
        result = 0;
    }
    if (!TestConvertLine(convert_line_input2, convert_line_assumed_output2)) {
        puts("FAIL: conversion: ConvertLine() | input 2");
        result = 0;
    }
    if (!TestConvertLine(convert_line_input3, convert_line_assumed_output3)) {
        puts("FAIL: conversion: ConvertLine() | input 3");
        result = 0;
    }
    if (!TestConvertLine(convert_line_input4, convert_line_assumed_output4)) {
        puts("FAIL: conversion: ConvertLine() | input 4");
        result = 0;
    }
    // ----

    // ----- TestCreateConvertedLine -----
    string words1[] = {};
    string words2[] = {};
    string words3[] = {"b8", "C", "T"};
    string words4[] = {"a", "b", "c"};
    string words5[] = {"c", "D", "g-r"};

    size_t words1_size = 0;
    size_t words2_size = 0;
    size_t words3_size = 3;
    size_t words4_size = 3;
    size_t words5_size = 3;

    int digits_sum1 = 0;
    int digits_sum2 = 49;
    int digits_sum3 = 0;
    int digits_sum4 = 12;
    int digits_sum5 = 9;

    string create_converted_line_assumed_output1 = "";
    string create_converted_line_assumed_output2 = "49";
    string create_converted_line_assumed_output3 = "b8 C T";
    string create_converted_line_assumed_output4 = "a b c 12";
    string create_converted_line_assumed_output5 = "c D g-r 9";

    if (!TestCreateConvertedLine(words1, words1_size, digits_sum1,
                create_converted_line_assumed_output1)) {
        puts("FAIL: conversion: CreateConvertedLine() | input 1");
        result = 0;
    }
    if (!TestCreateConvertedLine(words2, words2_size, digits_sum2,
                create_converted_line_assumed_output2)) {
        puts("FAIL: conversion: CreateConvertedLine() | input 2");
        result = 0;
    }
    if (!TestCreateConvertedLine(words3, words3_size, digits_sum3,
                create_converted_line_assumed_output3)) {
        puts("FAIL: conversion: CreateConvertedLine() | input 3");
        result = 0;
    }
    if (!TestCreateConvertedLine(words4, words4_size, digits_sum4,
                create_converted_line_assumed_output4)) {
        puts("FAIL: conversion: CreateConvertedLine() | input 4");
        result = 0;
    }
    if (!TestCreateConvertedLine(words5, words5_size, digits_sum5,
                create_converted_line_assumed_output5)) {
        puts("FAIL: conversion: CreateConvertedLine() | input 5");
        result = 0;
    }
    // ----

    // ----- TestToString -----
    int number1 = 0;
    int number2 = 123456789;
    int number3 = 10000;

    string to_string_assumed_output1 = "0";
    string to_string_assumed_output2 = "123456789";
    string to_string_assumed_output3 = "10000";

    if (!TestToString(number1, to_string_assumed_output1)) {
        puts("FAIL: conversion: ToString() | input 1");
        result = 0;
    }
    if (!TestToString(number2, to_string_assumed_output2)) {
        puts("FAIL: conversion: ToString() | input 2");
        result = 0;
    }
    if (!TestToString(number3, to_string_assumed_output3)) {
        puts("FAIL: conversion: ToString() | input 3");
        result = 0;
    }
    // ----

    return result;
}

int TestConvertLine(const string input,
                    const string assumed_output) {
    TESTS_RUN++;
    string converted_line;
    
    ConvertLine(input, &converted_line);

    int result = 1;

    if (strcmp(converted_line, assumed_output)) {
        result = 0;
    }

    free(converted_line);
    
    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}

int TestCreateConvertedLine(const string *words,
                            size_t words_size,
                            int digits_sum,
                            const string assumed_output) {
    TESTS_RUN++;
    string converted_line = CreateConvertedLine(words, words_size, digits_sum);

    int result = 1;

    if (strcmp(converted_line, assumed_output)) {
        result = 0;
    }

    free(converted_line);
    
    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}

int TestToString(int number,
                 const string assumed_output) {
    TESTS_RUN++;
    string string_number = ToString(number);

    int result = 1;

    if (strcmp(string_number, assumed_output)) {
        result = 0;
    }

    free(string_number);
    
    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }
    return result;
}
