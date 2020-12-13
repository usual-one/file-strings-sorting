#include <stdio.h>

#include "include/test_utils.h"
#include "include/test_types_split.h"
#include "include/test_global.h"

int TESTS_RUN = 0;
int TESTS_SUCCEEDED = 0;
int TESTS_FAILED = 0;

int main(int argc, char* argv[]) {
    TestUtils();
    TestTypesSplit();

    printf("%d tests run: %d succeeded, %d failed\n", TESTS_RUN, TESTS_SUCCEEDED, TESTS_FAILED);
    return 0;
}
