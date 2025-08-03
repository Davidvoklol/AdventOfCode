#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("No input file provided...\n");
		exit(1);
	};

	FILE* input = fopen(argv[1], "r");
	if (!input) {
		printf("Couldn't open '%s'\n", argv[1]);
		exit(1);
	}

	int* left_nums = calloc(1, sizeof(int));
	int left_size = 1;
	int left_length = 0;

	int* right_nums = calloc(1, sizeof(int));
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
				left_nums = realloc(left_nums, sizeof(int) * left_size);
			}
			left_nums[left_length] = atoi(token1);
			left_length++;
		}

		char* token2 = strtok(NULL, "   ");
		if (token2) {
			if (right_length >= right_size) {
				right_size *= 2;
				right_nums = realloc(right_nums, sizeof(int) * right_size);
			}
			right_nums[right_length] = atoi(token2);
			right_length++;
		}

		count++;
	}

	if (left_length == right_length) {
		for (int i = left_length; i > 0; i--) {
			for (int j = 1; j < i; j++) {
				int left = left_nums[j - 1];
				int right = left_nums[j];
				if (left > right) {
					int temp = left;
					left_nums[j - 1] = right;
					left_nums[j] = temp;
				}
				left = right_nums[j - 1];
				right = right_nums[j];
				if (left > right) {
					int temp = left;
					right_nums[j - 1] = right;
					right_nums[j] = temp;
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
		sum += abs(left_nums[i] - right_nums[i]);
	}
	printf("Sum: %i\n", sum);

	free(left_nums);
	free(right_nums);
	fclose(input);
}
