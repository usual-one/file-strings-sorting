#include <stdlib.h>
#include <string.h>

#include "../include/files.h"


int CopyContent(const string dest_path,
                const string src_path,
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

    string line = NULL;
    while (!feof(read_fd)) {
        if (ReadLine(read_fd, &line, line_size) == -1) {
            fclose(read_fd);
            fclose(write_fd);
            return -1;    
        }
        if (WriteLine(write_fd, line, !feof(read_fd)) == -1) {
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
             string *line,
             int line_size) {
    if (feof(fd) || !fd) {
        return -1; // incorrect file descriptor
    }

    *line = (string) malloc(line_size * sizeof(char));
    for (size_t i = 0; i < line_size; i++) {
        (*line)[i] = fgetc(fd);
        if ((*line)[i] == EOF || (*line)[i] == '\n') {
            (*line)[i] = '\0';
            return 0; 
        }
    }

    free(*line);
    return -1; // line exceeded `line_size`
}

int WriteLine(FILE *fd,
              const string line,
              char append_newline) {
    if (feof(fd) || !fd) {
        return -1; // incorrect file descriptor
    }

    fwrite(line, sizeof(char), strlen(line), fd);  
    if (append_newline) {
        fputc('\n', fd);
    }
    return 0;
}

