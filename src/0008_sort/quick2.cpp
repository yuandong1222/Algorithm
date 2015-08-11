#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void quick_sort(int* data, int start, int end) {
	int temp;

	if (start >= end)
		return;

	int middle = (start + end) / 2;
	if (data[middle] > data[start] && data[middle] < data[end]) {
		temp = data[middle];
		data[middle] = data[start];
		data[start] = temp;
	}
	if (data[middle] < data[start] && data[middle] > data[end]) {
		temp = data[middle];
		data[middle] = data[start];
		data[start] = temp;
	}
	if (data[end] > data[start] && data[end] < data[middle]) {
		temp = data[end];
		data[end] = data[start];
		data[start] = temp;
	}
	if (data[end] < data[start] && data[end] > data[middle]) {
		temp = data[end];
		data[end] = data[start];
		data[start] = temp;
	}

	int index = start;
	for (int i = start + 1; i < end; i++) {
		if (data[i] >= data[start])
			continue;

		if (index == i - 1) {
			index++;
			continue;
		}

		index++;
		temp = data[index];
		data[index] = data[i];
		data[i] = temp;
	}

	temp = data[index];
	data[index] = data[start];
	data[start] = temp;

	quick_sort(data, start, index);
	quick_sort(data, index + 1, end);
}

void sort(int* data, int length) {
	quick_sort(data, 0, length);
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
