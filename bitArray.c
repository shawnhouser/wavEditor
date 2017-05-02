#include "bitArray.h"

bool getBit(char *array, int index) {
    return 1 & (array[index / 8] >> (index % 8));
}

void toggleBit(char *array, int index) {
    array[index / 8] ^= 1 << (index % 8);
}

void setBit(char* array, int index, int value){
    if(getBit(array, index) != value){
        toggleBit(array, index);
    }
}


