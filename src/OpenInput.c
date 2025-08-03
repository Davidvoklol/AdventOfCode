#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* OpenInput(char* file_path) {
	char resolved_path[4096];
	realpath(file_path, resolved_path);

	char* last = strrchr(resolved_path, '/');
	if (last) {
		*last = '\0';
		char* second_last = strrchr(resolved_path, '/');
		if (second_last) {
			*second_last = '\0';
		}
	}

	char input_name[strlen(resolved_path) + strlen("/input.txt") + 1];
	snprintf(input_name, sizeof(input_name), "%s/input.txt", resolved_path);

	FILE* input = fopen(input_name, "r");
	if (!input) {
		printf("Couldn't open '%s'\n", input_name);
		exit(1);
	}

	return input;
}
