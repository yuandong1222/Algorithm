#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

int* temp_data = NULL;

void merging_sort(int* data, int start, int end) {
	if (start == end - 1)
		return;

	int middle = (start + end) / 2;
	merging_sort(data, start, middle);
	merging_sort(data, middle, end);

	int temp_data_index = start;
	int start_index = start;
	int middle_index = middle;
	while (start_index < middle && middle_index < end){
		if (data[start_index] < data[middle_index])
			temp_data[temp_data_index++] = data[start_index++];
		else
			temp_data[temp_data_index++] = data[middle_index++];
	}
	while(start_index < middle) {
		temp_data[temp_data_index++] = data[start_index++];
	}
	while(middle_index < end) {
		temp_data[temp_data_index++] = data[middle_index++];
	}
	
	start_index = start;
	temp_data_index = start;
	while (start_index < end) {
		data[start_index++] = temp_data[temp_data_index++];
	}
}

void sort(int* data, int length) {
	temp_data = new int[length];

	merging_sort(data, 0, length);

	delete [] temp_data;
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
