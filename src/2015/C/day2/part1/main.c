#include "../../include/custom.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (checkinput(argc, argv) == FAIL) exit(1);

	FILE *input = verbose_fopen(argv[1], "r");
	if (!input) exit(1);

	while (1) {
	}

	fclose(input);
}
