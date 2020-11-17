#include "stdio.h"


// `line_size` includes null-terminating char
int CopyContent(const char* dest_path,
                const char* src_path,
                int line_size); 

// `line_size` includes null-terminating char
// `line` will be allocated and must be freed
int ReadLine(FILE *fd, 
             char* line,
             int line_size);

int WriteLine(FILE *fd, 
              const char* line);

