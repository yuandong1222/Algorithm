#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void sort(int* data, int length) {
	int temp;
	for (int i = 1; i < length; i++) {
		if (data[i] >= data[i - 1])
			continue;

		temp = data[i];
		data[i] = data[i - 1];

		int j = 0;
		for (j = i - 2; j >= 0 && data[j] > temp; j--) {
			data[j + 1] = data[j];
		}
		data[j + 1] = temp;
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
