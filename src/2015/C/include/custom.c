#include "custom.h"
#include <stdio.h>

void checkinput(int argc, char *argv[]) {
	if (argc < 2) {
		printf("No input were provided...\n");
		printf("Expected: %s [input]\n", argv[0]);
		exit(1);
	}
}
