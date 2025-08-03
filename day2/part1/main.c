#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	long sum = 0;
	while (1) {
		char line[69];
		char* success = fgets(line, sizeof(line), input);
		if (!success) break;

		char* l = strtok(line, "x");
		char* w = strtok(NULL, "x");
		char* h = strtok(NULL, "x");

		if (l && h && w) {
			int width = atoi(w);
			int height = atoi(h);
			int length = atoi(l);

			int w_h = width * height;
			int w_l = width * length;
			int h_l = height * length;

			int min;
			if (w_h < w_l) min = w_h < h_l ? w_h : h_l;
			else min = w_l < h_l ? w_l : h_l;

			sum += 2 * w_h + 2 * w_l + 2 * h_l + min;
		}
		else {
			printf("Couldn't read the data...\n");
			break;
		}
	}

	printf("square feet: %li\n", sum);

	fclose(input);
}
