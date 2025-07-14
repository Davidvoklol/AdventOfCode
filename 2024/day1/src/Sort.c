#include "./Sort.h"

void Swap_int(int* array, int i1, int i2) {
	int temp = array[i1];
	array[i1] = array[i2];
	array[i2] = temp;
}

void BubbleSort_int(int* array, int size) {
	for (int end = size; end > 0; end--) {
		for (int i = 1; i < size; i++) {
			if (array[i - 1] > array[i]) {
				Swap_int(array, i - 1, i);
			}
		}
	}
}
