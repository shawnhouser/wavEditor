#include <stdbool.h>

#ifndef BIT_ARRAY_INCLUDED
#define BIT_ARRAY_INCLUDED

bool getBit(char *array, int index);
void toggleBit(char *array, int index);
void setBit(char *array, int index, int value);

#endif