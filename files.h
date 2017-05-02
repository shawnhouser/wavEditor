#include <stdio.h>          // printf()
#include <stdlib.h>         // malloc(), exit()

#include <sys/stat.h>       // stat()
#include <unistd.h>         // close()
#include <fcntl.h>          // open()
#include <sys/mman.h>       // mmap()

#ifndef FILES_INCLUDED
#define FILES_INCLUDED

struct fileInfo {
    struct stat fileStats;
    char* file;
};
struct fileInfo *openFile(char *fileName);
void closeFile(struct fileInfo *fileToClose);

#endif