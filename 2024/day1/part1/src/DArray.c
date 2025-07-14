#include "./DArray.h"

struct DArray_int NewDArray_int(int size) {
	int* array = malloc(size * sizeof(int));
	struct DArray_int darray = { size, array };
	return darray;
}

void SetDArray_int(struct DArray_int* darray, int index, int number) {
	if (index >= darray->size) {
		int old_size = darray->size;
		int new_size = 1;
		while (index >= new_size) { new_size *= 2; }

		int* temp = realloc(darray->array, new_size * sizeof(int));
		if (!temp) return;
		darray->array = temp;
		darray->size = new_size;

		memset(temp + old_size, 0, (new_size - old_size) * sizeof(int));
	}
	darray->array[index] = number;
}
