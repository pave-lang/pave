#ifndef PAVE_FS
#define PAVE_FS

#include <stdio.h>

int path_exists(const char *path);
int create_directory(const char *path);

FILE *mem_file_open(void);
int mem_file_save(FILE *file, const char *path);
void mem_file_close(FILE *file);

#endif
