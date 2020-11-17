#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "include/files.h"
#include "include/conversion.h"


int main(int argc, char* argv[]) {
    const int max_line_size = 10 * 100 + 9 + 1;

    if (!argc) {
        return -1;
    }
    char* read_path = argv[1];

    char* write_path = malloc((strlen(read_path) + strlen(".swp") + 1) * sizeof(char));
    strcpy(write_path, read_path);
    strcat(write_path, ".swp");

    // ----- converting file content -----
    if (ConvertFile(write_path, read_path, max_line_size) == -1) {
        free(write_path);
        return -1;
    }
    // -----

    // ----- moving result content from swap to original file -----  
    if (CopyContent(read_path, write_path, max_line_size) == -1) {
        free(write_path);
        return -1;
    }

    if (remove(write_path)) {
        free(write_path);
        return -1;
    }
    // -----

    free(write_path);
    return 0;
}
