#include "performance_test.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

int run_count = 0;
int program_count = 0;
int test_count = 0;

const char* get_program_name(const char* program_full_name) {
	return rindex(program_full_name, '/') + 1;
}
string get_test_name(const char* test_full_name) {
	int start = rindex(test_full_name, '/') - test_full_name + PERFORMANCE_TEST_INPUT_FILE_PERFIX_LENGTH;
	int length = (rindex(test_full_name, '.') - test_full_name) - start;
	string s(test_full_name);
	return s.substr(start + 1, length - 1);
}

int main(int argc, char const* argv[])
{
	int i = 0, j = 0;
	const char* run_count_string = argv[1];
	string command_text;

	//Initial	
	run_count = atoi(argv[1]);
	program_count = atoi(argv[2]);
	test_count = atoi(argv[3]);

	//Open file	
	ofstream result_file(RESULT_FILE_NAME);
	result_file << run_count << " " << program_count << " " << test_count << endl;

	//Each program in one line
	for (i = 0; i < program_count; i++) {
		const char* program_full_name = argv[i + 4];
		string program_name = get_program_name(program_full_name);
		result_file << program_name << endl;
	}
	result_file.close();

	//Run tests
	for (i = 0; i < test_count; i++) {
		const char* test_input_file_full_name = argv[i + 4 + program_count];
		string test_name = get_test_name(test_input_file_full_name);

		result_file.open(RESULT_FILE_NAME, ios::app);
		result_file << test_name << endl;
		result_file.close();

		command_text.clear();
		command_text.append("cp ");
		command_text.append(test_input_file_full_name);
		command_text.append(" bin/test.in");
		command_text.append("\n");
		cout << command_text.c_str();
		system(command_text.c_str());

		for (j = 0; j < program_count; j++) {
			const char* program_full_name = argv[j + 4];

			command_text.clear();
			command_text.append(program_full_name);
			command_text.append(" ");
			command_text.append(run_count_string);
			command_text.append(" >> ");
			command_text.append(RESULT_FILE_NAME);
			command_text.append("\n");
			cout << command_text.c_str();
			system(command_text.c_str());
		}
	}
}
