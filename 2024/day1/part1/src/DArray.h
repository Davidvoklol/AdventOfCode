#pragma once
#include <stdlib.h>
#include <string.h>

struct DArray_int {
	int size;
	int* array;
};

struct DArray_int NewDArray_int(int size);
void SetDArray_int(struct DArray_int* darray, int index, int number);

