#include "../../include/custom.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	checkinput(argc, argv);

	FILE *input = fopen(argv[1], "r");
	if (!input) {
		printf("Couldn't open %s...\n", argv[1]);
		exit(1);
	}

	int floor = 0;
	while (1) {
		char buffer[420];

		char *success = fgets(buffer, sizeof(buffer), input);
		if (!success)  break;

		for (char *current_ptr = buffer, *end = buffer + sizeof(buffer); current_ptr < end && *current_ptr != '\0'; current_ptr++) {
			char current = *current_ptr;
			if (current == '\n') continue;

			if (current == '(') floor++;
			else if (current == ')') floor--;
		}
	}

	printf("answer: %i\n", floor);
}

