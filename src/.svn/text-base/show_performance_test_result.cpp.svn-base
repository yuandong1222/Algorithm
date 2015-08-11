#include "performance_test.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>

#define COLUMN_SPACE    4
#define MAX_LINE_LENGTH 256

using namespace std;

const int min_width = 8;

int run_count = 0;
int program_count = 0;
int test_count = 0;

int main(int argc, char const* argv[])
{
	int i = 0, j = 0;
	char line[MAX_LINE_LENGTH];

	ifstream result_file(RESULT_FILE_NAME);
	result_file >> run_count >> program_count >> test_count;
	result_file.getline(line, MAX_LINE_LENGTH);
	int* column_widths = new int[program_count];

	//first_line
	cout << endl;
	cout << setw(min_width) << right << " ";
	for (i = 0; i < program_count; i++) {
		result_file.getline(line, MAX_LINE_LENGTH);

		column_widths[i] = strlen(line) + 1;
		if (column_widths[i] <= min_width)
			column_widths[i] = min_width;

		cout << setw(column_widths[i]) << right << line;
	}
	cout << endl;

	//test
	for (i = 0; i < test_count; i++) {
		result_file.getline(line, MAX_LINE_LENGTH);
		cout << setw(min_width) << left << line;
		for (j = 0; j < program_count; j++) {
			result_file.getline(line, MAX_LINE_LENGTH);
			cout << setw(column_widths[j]) << right << line;
		}
		cout << endl;
	}
	cout << endl;

	cout << "Run each test for " << run_count << " times." << endl;

	return 0;
}
