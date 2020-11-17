#include "stdlib.h"
#include "string.h"

#include "../include/files.h"


int CopyContent(const char* dest_path,
                const char* src_path,
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

    char *line;
    while (!feof(read_fd)) {
        if (ReadLine(read_fd, line, line_size) == -1) {
            fclose(read_fd);
            fclose(write_fd);
            return -1;    
        }
        if (WriteLine(write_fd, line) == -1) {
            free(line);
            fclose(read_fd);
            fclose(write_fd);
            return -1;
        }
        free(line);
    }

    fclose(read_fd);
    fclose(write_fd);
    return 0;
}

int ReadLine(FILE *fd,
             char* line,
             int line_size) {
    if (feof(fd) || !fd) {
        return -1;
    }

    line = malloc(line_size * sizeof(char));
    for (size_t i = 0; i < line_size; i++) {
        char read_char = fgetc(fd);
        if (read_char == EOF || read_char == '\n') {
            line[i] = '\0';
            break;
        }
        line[i] = read_char;
    }

    if (line[line_size - 1] != '\0') {
        return -1;
        free(line);
    }

    return 0;
}

int WriteLine(FILE *fd,
              const char* line) {
    if (feof(fd) || !fd) {
        return -1;
    }

    fwrite(line, sizeof(char), strlen(line), fd);  
    fputc('\n', fd);
    return 0;
}

