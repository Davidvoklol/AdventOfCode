#include "../../include/custom.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	checkinput(argc, argv);

	FILE *input = verbose_fopen(argv[1], "r");
	if (!input) exit(1);

	fclose(input);
}
