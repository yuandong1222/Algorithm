#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

int count;
int result_count;
int* chessboard;

bool can_put(int row, int column) {
	for (int i = 0; i < count; i++) {
		if (chessboard[row * count + i] == 1)
			return false;
		if (chessboard[i * count + column] == 1)
			return false;
	}

	int i, j;
	i = row - 1, j = column - 1;
	while (i >= 0 && j >= 0) {
		if (chessboard[i * count + j] == 1)
			return false;
		i--;
		j--;
	}
	i = row + 1, j = column + 1;
	while (i < count && j < count) {
		if (chessboard[i * count + j] == 1)
			return false;
		i++;
		j++;
	}
	i = row + 1, j = column - 1;
	while (i < count && j >= 0) {
		if (chessboard[i * count + j] == 1)
			return false;
		i++;
		j--;
	}
	i = row - 1, j = column + 1;
	while (i >= 0 && j < count) {
		if (chessboard[i * count + j] == 1)
			return false;
		i--;
		j++;
	}

	return true;
}

void queen_action(int line) {
	if (line == count) {
		result_count++;
		return;
	}

	for (int i = 0; i < count; i++) {
		if (!can_put(line, i))
			continue;

		chessboard[line * count + i] = 1;
		queen_action(line + 1);
		chessboard[line * count + i] = 0;
	}
}

void queen() {
	result_count = 0;
	chessboard = new int[count * count];
	for (int i = 0; i < count * count; i++) {
		chessboard[i] = 0;
	}

	queen_action(0);

	delete [] chessboard;
}

void Problem::Run(istream& input, ostream& output) {
	input >> count;
	while (count != 0) {
		queen();
		output << result_count << endl;
		input >> count;
	}
}
