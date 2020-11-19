#ifndef FILES_H
#define FILES_H

#include <stdio.h>

#include "types.h"


// `line_size` includes null-terminating char
int CopyContent(const string dest_path,
                const string src_path,
                int line_size); 

// `line_size` includes null-terminating char
// `line` will be allocated and must be freed
int ReadLine(FILE *fd, 
             string *line,
             int line_size);

int WriteLine(FILE *fd, 
              const string line,
              char append_newline);

#endif // FILES_H
