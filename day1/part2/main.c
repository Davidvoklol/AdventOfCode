#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("No input provided...\n");
		exit(1);
	}

	FILE* input = fopen(argv[1], "r");
	if (!input) {
		printf("Couldn't open %s\n", argv[1]);
		exit(1);
	}

	int floor = 0;
	int index = 1;
	while (1) {
		char buffer[420];
		char* success = fgets(buffer, sizeof(buffer), input);
		if (!success) break;

		for (int i = 0; buffer[i] != 0; i++, index++) {
			if (buffer[i] == '(') floor++;
			else if (buffer[i] == ')') floor--;

			if (floor == -1) {
				printf("entering basement at: %i\n", index);
				break;
			}
		}
		if (floor == -1) break;
	}

	fclose(input);
}
