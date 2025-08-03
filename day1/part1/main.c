#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	if (argc < 2) {
		printf("No input prvided...\n");
		exit(1);
	}

	FILE* input = fopen(argv[1], "r");
	if (!input) {
		printf("Couldn't open %s\n", argv[1]);
		exit(1);
	}

	int floor = 0;

	while (1) {
		char line[420];
		char* success = fgets(line, sizeof(line), input);
		if (!success) break;

		for (int i = 0; line[i] != 0; i++) {
			if (line[i] == '(') floor++;
			else if (line[i] == ')') floor--;
		}
	}

	printf("floor: %i\n", floor);

	fclose(input);
}
