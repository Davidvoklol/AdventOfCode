#include "../../include/custom.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (checkinput(argc, argv) == FAIL) exit(1);

	FILE *input = verbose_fopen(argv[1], "r");
	if (!input) exit(1);

	int floor = 0;
	int index = 0;
	char buffer[420];
	while (1 && floor >= 0) {
		buffer[0] = '\0';

		char *success = fgets(buffer, sizeof(buffer), input);
		if (!success)  break;

		for (char *current_ptr = buffer, *end = buffer + sizeof(buffer); current_ptr < end && *current_ptr != '\0'; current_ptr++) {
			index++;

			char current = *current_ptr;
			if (current == '\n') continue;

			if (current == '(') floor++;
			else if (current == ')') floor--;

			if (floor < 0) break;
		}
	}

	if (floor < 0) printf("answer: %i\n", index);	
	else printf("no answer found");

	fclose(input);
}


