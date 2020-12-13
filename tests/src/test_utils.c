#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/tests/test_utils.h"
#include "../../include/tests/test_global.h"
#include "../../include/utils.h"


int TestUtils() {
    int result = 1; 

    // ----- TestSum -----
    char digits1[] = {};
    char digits2[] = {1};
    char digits3[] = {2, 3, 4};

    size_t digits1_size = 0;
    size_t digits2_size = 1;
    size_t digits3_size = 3;

    int assumed_sum_output1 = 0;
    int assumed_sum_output2 = 1;
    int assumed_sum_output3 = 9;

    if (!TestSum(digits1, digits1_size, assumed_sum_output1)) {
        result = 0;
        puts("FAIL: utils: Sum() | input 1");
    }
    if (!TestSum(digits2, digits2_size, assumed_sum_output2)) {
        result = 0;
        puts("FAIL: utils: Sum() | input 2");
    }
    if (!TestSum(digits3, digits3_size, assumed_sum_output3)) {
        result = 0;
        puts("FAIL: utils: Sum() | input 3");
    }
    // -----

    // ----- TestSort -----
    string arr1[] = {};
    string arr2[] = {"a"};
    string arr3[] = {"a", "b", "c", "d"};
    string arr4[] = {"a", "B", "c", "D"};
    string arr5[] = {"c", "a", "d", "b"};
    string arr6[] = {"c", "a", "D", "B"};
    
    size_t arr1_size = 0;
    size_t arr2_size = 1;
    size_t arr3_size = 4;
    size_t arr4_size = 4;
    size_t arr5_size = 4;
    size_t arr6_size = 4;

    string assumed_sort_output1[] = {};
    string assumed_sort_output2[] = {"a"};
    string assumed_sort_output3[] = {"a", "b", "c", "d"};
    string assumed_sort_output4[] = {"a", "B", "c", "D"};
    string assumed_sort_output5[] = {"c", "a", "d", "b"};
    string assumed_sort_output6[] = {"c", "a", "D", "B"};

    if (!TestSort(arr1, arr1_size, assumed_sort_output1)) {
        result = 0;
        puts("FAIL: utils: Sort() | input 1");
    }
    if (!TestSort(arr2, arr2_size, assumed_sort_output2)) {
        result = 0;
        puts("FAIL: utils: Sort() | input 2");
    }
    if (!TestSort(arr3, arr3_size, assumed_sort_output3)) {
        result = 0;
        puts("FAIL: utils: Sort() | input 3");
    }
    if (!TestSort(arr4, arr4_size, assumed_sort_output4)) {
        result = 0;
        puts("FAIL: utils: Sort() | input 4");
    }
    if (!TestSort(arr5, arr5_size, assumed_sort_output5)) {
        result = 0;
        puts("FAIL: utils: Sort() | input 5");
    }
    if (!TestSort(arr6, arr6_size, assumed_sort_output6)) {
        result = 0;
        puts("FAIL: utils: Sort() | input 6");
    }
    // -----
    
    return result;
}

int TestSum(const char *digits,
            size_t digits_size,
            int assumed_output) {
    TESTS_RUN++;
    if (assumed_output == Sum(digits, digits_size)) {
        TESTS_SUCCEEDED++;
        return 1;
    } else {
        TESTS_FAILED++;
        return 0;
    } 
}

int TestSort(const string *arr,
             size_t arr_size,
             const string *assumed_output) {
    TESTS_RUN++;
    int result = 1;

    string *arr_copy = (string *) malloc(arr_size * sizeof(string));
    for (size_t i = 0; i < arr_size; i++) {
        arr_copy[i] = (string) malloc((strlen(arr[i]) + 1) * sizeof(string));
        strcpy(arr_copy[i], arr[i]);
    }

    Sort(&arr_copy, arr_size);
    for (size_t i = 0; i < arr_size; i++) {
        if (strcmp(arr_copy[i], assumed_output[i])) {
            result = 0;
            break;
        }
    }

    for (size_t i = 0; i < arr_size; i++) {
        free(arr_copy[i]);
    }
    free(arr_copy);

    if (result) {
        TESTS_SUCCEEDED++;
    } else {
        TESTS_FAILED++;
    }

    return result;
}
