#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/files.h"
#include "include/conversion.h"
#include "include/types.h"


int main(int argc, char* argv[]) {
    puts("main:0: program started"); //DEBUG

    const int max_line_size = 1000 + 1 + 1; // '\n' + '\0'

    if (argc == 1) {
        puts("No path provided");
        return -1;
    }
    string read_path = argv[1];

    string write_path = (string) malloc((strlen(read_path) + strlen(".swp") + 1) * sizeof(char));
    strcpy(write_path, read_path);
    strcat(write_path, ".swp");

    printf("main:1: read_path: %s\n", read_path); // DEBUG
    printf("main:2: write_path: %s\n", write_path); //DEBUG

    // ----- converting file content -----
    if (ConvertFile(write_path, read_path, max_line_size) == -1) {
        puts("Incorrect file");
        remove(write_path);
        free(write_path);
        return -1;
    }
    // -----
    puts("main:3: file converted"); //DEBUG

    // ----- moving result content from swap to original file -----  
    if (CopyContent(read_path, write_path, max_line_size) == -1) {
        free(write_path);
        remove(write_path);
        puts("Incorrect file");
        return -1;
    }
    puts("main:4: content copied to original file"); //DEBUG

    if (remove(write_path)) {
        free(write_path);
        puts("Incorrect file");
        return -1;
    }
    // -----
    puts("main:5: swap file removed"); // DEBUG

    free(write_path);
    puts("main:6: program finished"); // DEBUG
    return 0;
}
