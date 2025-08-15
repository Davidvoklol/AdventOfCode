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
