#include "files.h"

/* Opens a file with MMap and returns important information */
struct fileInfo *openFile(char *fileName){
    struct fileInfo *rFI = (struct fileInfo *) malloc(sizeof(struct fileInfo)); // returnFileInfo

    /* Open base File and get information */
    char baseFile = open(fileName, O_RDONLY);
    if (baseFile == -1) {
	    printf("Error opening file for reading\n");
	    exit(EXIT_FAILURE);
    }
    if (stat(fileName, &rFI->fileStats) == -1){
		printf("Error with Obtaining File Stats\n");
		exit(0);
	}

    /* MMap the base File */
    rFI->file = mmap(0, rFI->fileStats.st_size, PROT_READ, MAP_SHARED, baseFile, 0);
    if (rFI->file == MAP_FAILED) {
	    printf("Error mmapping the file\n");
	    exit(EXIT_FAILURE);
    }
    /* Close the base File */
    close(baseFile);

    /* Return the MMapped file */
    return rFI;
}
void closeFile(struct fileInfo *fileToClose){
    if (munmap(fileToClose->file, fileToClose->fileStats.st_size) == -1) {
	    printf("Error un-mmapping the file\n");
    }
}