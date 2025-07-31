#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	char resolved_path[4096];
	realpath(argv[0], resolved_path);

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

	int* nums_left = calloc(1, sizeof(int));
	int left_size = 1;
	int left_length = 0;

	int* nums_right = calloc(1, sizeof(int));
	int right_size = 1;
	int right_length = 0;

	int count = 0;
	while (1) {
		char line[420];
		char* success = fgets(line, sizeof(line), input);
		if (!success) break;

		char* new_line = strstr(line, "\n");
		if (new_line) *new_line = '\0';
		
		char* token1 = strtok(line, "   ");
		if (token1) {
			if (left_length >= left_size) {
				left_size *= 2;
				nums_left = realloc(nums_left, sizeof(int) * left_size);
			}
			nums_left[left_length] = atoi(token1);
			left_length++;
		}

		char* token2 = strtok(NULL, "   ");
		if (token2) {
			if (right_length >= right_size) {
				right_size *= 2;
				nums_right = realloc(nums_right, sizeof(int) * right_size);
			}
			nums_right[right_length] = atoi(token2);
			right_length++;
		}

		count++;
	}

	if (left_length == right_length) {
		for (int i = left_length; i > 0; i--) {
			for (int j = 1; j < i; j++) {
				int left = nums_left[j - 1];
				int right = nums_left[j];
				if (left > right) {
					int temp = left;
					nums_left[j - 1] = right;
					nums_left[j] = temp;
				}
			}
		}
		for (int i = right_length; i > 0; i--) {
			for (int j = 1; j < i; j++) {
				int left = nums_right[j - 1];
				int right = nums_right[j];
				if (left > right) {
					int temp = left;
					nums_right[j - 1] = right;
					nums_right[j] = temp;
				}
			}
		}
	}
	else {
		printf("The arrays are not the same sime...\n");
		exit(1);
	}

	int sum = 0;
	for (int i = 0; i < left_length; i++) {
		sum += abs(nums_left[i] - nums_right[i]);
	}
	printf("Sum: %i\n", sum);
}
