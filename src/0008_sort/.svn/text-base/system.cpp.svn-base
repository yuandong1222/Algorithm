#include "problem.h"

#include <iostream>
#include <algorithm>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void Problem::Run(istream& input, ostream& output) {
	int length = 0;
	input >> length;

	int *data = new int[length];
	while (length != 0) {
		for (int i = 0; i < length; i++) {
			input >> data[i];
		}

		sort(data, data + length);
		
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
