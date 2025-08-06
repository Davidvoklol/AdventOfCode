#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;
const int FALSE = 0;
const int SANTA = 0;
const int ROBOT = 1;

struct pos {
	int x; int y;
};

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

	int positions_size = 69;
	struct pos* positions = calloc(positions_size, sizeof(struct pos));
	int positions_count = 1;

	struct pos santa_position = { 0, 0 };
	struct pos robot_position = { 0, 0 };

	positions[0] = robot_position;
	int turn = SANTA;

	while (1) {
		char line[69];
		char* success = fgets(line, sizeof(line), input);
		if (!success) break;


		for (int i = 0; line[i]; i++) {
			if (positions_count >= positions_size) {
				positions_size <<= 1;
				positions = realloc(positions, positions_size * sizeof(struct pos));
			}

			char move = line[i];

			if (move == '^') turn == ROBOT ? robot_position.y++ : santa_position.y++;
			else if (move == '<') turn == ROBOT ? robot_position.x-- : santa_position.x--;
			else if (move == '>') turn == ROBOT ? robot_position.x++ : santa_position.x++;
			else if (move == 'v') turn == ROBOT ? robot_position.y-- : santa_position.y--;

			positions[positions_count++] = turn == ROBOT ? robot_position : santa_position;

			turn = turn == SANTA ? ROBOT : SANTA;
		}
	}

	struct pos distinct_positions[positions_count];
	int distinct_positions_count = 0;

	for (int i = 0; i < positions_count; i++) {
		struct pos target = positions[i];

		int IS_DISTINCT = TRUE; 
		for (int j = 0; j < distinct_positions_count && IS_DISTINCT; j++) {
			struct pos current = distinct_positions[j];
			if (current.x == target.x && current.y == target.y) IS_DISTINCT = FALSE;
		}

		if (IS_DISTINCT) {
			distinct_positions[distinct_positions_count] = target;
			distinct_positions_count++;
		}
	}

	printf("distinct houses: %i out of %i\n", distinct_positions_count, positions_count);

	free(positions);
	fclose(input);
}


