#include "custom.h"
#include <stdio.h>

int checkinput(int argc, char *argv[]) {
	if (argc < 2) {
		printf("No input were provided...\n");
		printf("Expected: %s [input]\n", argv[0]);
		return FAIL;
	}
	return SUCCESS;
}

FILE *verbose_fopen(const char *filename, const char *modes) {
	FILE *f = fopen(filename, modes);
	if (!f) printf("Couldn't open %s...\n", filename);
	return f;
}

int min(int array[], long size) {
	if (size < 1) return 0;

	int min = array[0];
	for (long i = 1; i < size; i++) {
		if (array[i] < min) min = array[i];
	}

	return min;
}

int max(int array[], long size) {
	if (size < 1) return 0;

	int max = array[0];
	for (long i = 1; i < size; i++) {
		if (array[i] > max) max = array[i];
	}

	return max;
}
