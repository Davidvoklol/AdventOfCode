#include "../../include/custom.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (checkinput(argc, argv) == FAIL) exit(1);

	FILE *input = verbose_fopen(argv[1], "r");
	if (!input) exit(1);

	int index = 0;
	char buffer[4];
	while (1) {
		buffer[0] = '\0';

		char *success = fgets(buffer, sizeof(buffer), input);
		if (!success)  break;

		printf("%i: [%s]\n", index, buffer);
		index++;
	}
}
