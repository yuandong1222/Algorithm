#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

const int dlta[5] = { 9, 5, 3, 2, 1};
const int dlta_length = 5;

void shell_insert(int* data, int length, int step) {
	int temp;
	for (int i = step; i < length; i++) {
		if (data[i] >= data[i - step])
			continue;

		temp = data[i];
		data[i] = data[i - step];

		int j = 0;
		for (j = i - 2 * step; j >= 0 && data[j] > temp; j -= step) {
			data[j + step] = data[j];
		}
		data[j + step] = temp;
	}
}

void sort(int* data, int length) {
	for (int i = 0; i < dlta_length; i++) {
		if (dlta[i] >= length)
			continue;

		shell_insert(data, length, dlta[i]);
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
