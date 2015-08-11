#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void adjust(int* data, int index, int length) {
	int value = data[index];
	for (int i = index * 2 + 1; i < length; i = i * 2 + 1) {
		if (i < length - 1 && data[i] < data[i + 1])
			i++;
		if (value >= data[i])
			break;

		data[index] = data[i];
		index = i;
	}

	data[index] = value;
}

void sort(int* data, int length) {
	for (int i = length / 2 - 1; i >= 0 ; i--) {
		adjust(data, i, length);
	}
	for (int i = length - 1; i > 0; i--) {
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;

		adjust(data, 0, i);
	}
}

void Problem::Run(istream& input, ostream& output) {
	int length = 0;
	input >> length;

	int *data = new int[length];
	while (length != 0) {
		for (int i = 0; i < length; i++) {
			input >> data[i];
		}

		sort(data, length);
		
		for (int i = 0; i < length; i++) {
			output << data[i];
			if (i < length - 1)
				output << ' ';
		}
		output << endl;

		int last_length = length;
		input >> length;
		if (last_length != length) {
			delete [] data;
			data = new int[length];
		}
	}
}

