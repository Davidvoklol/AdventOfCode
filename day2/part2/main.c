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
			int _l = atoi(l);
			int _w = atoi(w);
			int _h = atoi(h);

			int min1;
			int min2;
			if (_l < _w) {
				min1 = _l;
				min2 = _w < _h ? _w : _h;
			} else {
				min1 = _w;
				min2 = _l < _h ? _l : _h;
			}

			sum += 2 * min1 + 2 * min2 + _l * _w * _h;
		}
		else {
			printf("Couldn't read the data...\n");
			break;
		}

	}

	printf("feet: %li\n", sum);

	fclose(input);
}

