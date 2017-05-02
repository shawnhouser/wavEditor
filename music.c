#include <stdio.h>
#include <stdlib.h>

#include "files.h"
#include "bitArray.h"

int main(int argc, char **argv){
    struct fileInfo *file = openFile("original.wav");
    char *a = file->file;
    for (int i = 1000000; i < 1010000; ++i) {
        //char currentNum =  file->file[i];
	    printf("%d",getBit(a, i));
        //printf("%c",i);
    }
    printf("\n");

    closeFile(file);
}