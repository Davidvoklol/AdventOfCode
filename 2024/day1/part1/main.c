#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/DArray.h"
#include "../src/Sort.h"

int main(int argc, char* argv[]) {
	char filename[30];
	strcat(filename, argv[0]);
	char* parent_border = strrchr(filename, '/');
	parent_border[0] = '\0';
	strcat(filename, "/input.txt");

	FILE* file = fopen(filename, "r");
	if (!file) exit(1);
	struct DArray_int array1 = NewDArray_int(1);
	struct DArray_int array2 = NewDArray_int(1);

	int index = 0;
	while (1) {
		char line[20];
		if (!fgets(line, sizeof(line), file)) break;
		char* new_line = strstr(line, "\n");
		if (new_line) new_line[0] = '\0';

		char* token1 = strtok(line, " ");
		char* token2 = strtok(NULL, " ");

		if (token1) SetDArray_int(&array1, index, atoi(token1));
		if (token2) SetDArray_int(&array2, index, atoi(token2));
		index++;
	}

	BubbleSort_int(array1.array, array1.size);
	BubbleSort_int(array2.array, array2.size);

	int sum = 0;
	for (int i = 0; i < array1.size; i++) {
		sum += abs(array2.array[i] - array1.array[i]);
	}
	printf("%i\n", sum);
}
