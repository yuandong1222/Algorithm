#include "problem.h"

#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_SPAN_UNIT 1000

using namespace algorithm;
using namespace std;

int main(int argc, char const* argv[])
{
	Problem problem;
	clock_t start_clock, end_clock;
	double time_span = 0;

	//read input file to input string buffer
	ifstream input_file(INPUT_FILE_NAME);
	stringbuf input_string_buf;
	while (!input_file.eof())
		input_string_buf.sputc(input_file.get());
	input_file.close();
	
	//output string buffer
	stringbuf output_string_buf;

	//initial input and output stream
	istream input(&input_string_buf);
	ostream output(&output_string_buf);

	//get count
	int count = 1;
	if (argc > 1) {
		count = atoi(argv[1]);
	}

	input.seekg(0, ios_base::beg);
	output.seekp(0, ios_base::beg);
	problem.SetUp(input, output);

	for (int i = 0; i < count; i++) {
		input.seekg(0, ios_base::beg);
		output.seekp(0, ios_base::beg);

		start_clock = clock();
		problem.Run(input, output);
		end_clock = clock();
		time_span += end_clock - start_clock;
	}
	
	input.seekg(0, ios_base::beg);
	output.seekp(0, ios_base::beg);
	problem.TearDown(input, output);

	//write output_buffer_string to file
	if (count == 1) {
		ofstream output_file(OUTPUT_FILE_NAME);
		string s = output_string_buf.str();
		for (unsigned int i = 0; i < s.length(); i++) {
			output_file.put(s[i]);
		}
		output_file.close();
	}

	time_span /= count;
	time_span /= CLOCKS_PER_SEC;
	time_span *= TIME_SPAN_UNIT;
	printf("%.2lf\n", time_span);

	return 0;
}

