#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

double problem_execution_time;
ifstream expect_output_file;
ifstream actual_output_file;

bool compare_exepct_and_actual_output_file(bool is_ingore_space) {
	expect_output_file.seekg(0);
	actual_output_file.seekg(0);

	char expect_char, actual_char;
	while (!expect_output_file.eof() && !actual_output_file.eof()) {
		expect_char = expect_output_file.get();
		actual_char = actual_output_file.get();

		if (is_ingore_space) {
			while (isspace(expect_char) && !expect_output_file.eof())
				expect_char = expect_output_file.get();

			while (isspace(actual_char) && !actual_output_file.eof())
				actual_char = actual_output_file.get();

			if (expect_output_file.eof() || actual_output_file.eof())
				break;
		}

		if (expect_char != actual_char) {
			cout << (int)expect_char << ' '<< (int)actual_char << endl;
			return false;
		}
	}

	if (expect_output_file.eof() && actual_output_file.eof())
		return true;

	if (!is_ingore_space)
		return false;

	if (expect_output_file.eof()) {
		while (!actual_output_file.eof()) {
			if (!isspace(actual_char))
				return false;
			actual_char = actual_output_file.get();
		}
	}
	if (actual_output_file.eof()) {
		while (!expect_output_file.eof()) {
			if (!isspace(expect_char))
				return false;
			expect_char = expect_output_file.get();
		}
	}

	return true;
}
bool is_passed() {
	return compare_exepct_and_actual_output_file(false);
}
bool is_format_error() {
	return compare_exepct_and_actual_output_file(true);
}

void show_cost_time() {
	printf("Problem cost time: %.2lf ms\n", problem_execution_time);
}
void show_passed() {
	printf("\033[1;40;32m%s\033[0m\n", "PASS");
	show_cost_time();
}
void show_format_error() {
	printf("\033[1;40;33m%s\033[0m\n", "FORMAT ERROR");
	show_cost_time();
}
void show_wrong_result() {
	printf("\033[1;40;31m%s\033[0m\n", "WRONG RESULT");
	show_cost_time();
}

int main(int argc, char const* argv[])
{
	cin >> problem_execution_time;

	char const* expect_output_file_name = argv[1];	
	char const* actual_output_file_name = argv[2];	
	expect_output_file.open(expect_output_file_name);
	actual_output_file.open(actual_output_file_name);

	if (!expect_output_file.good()) {
		cout << "Except output file not found: " << expect_output_file;
		return 0;
	}
	if (!actual_output_file.good()) {
		cout << "Problem output file not found: " << actual_output_file;
		return 0;
	}

	if (is_passed()) {
		show_passed();
		return 0;
	}

	if (is_format_error()) {
		show_format_error();
		return 0;
	}

	show_wrong_result();
	return 0;
}
