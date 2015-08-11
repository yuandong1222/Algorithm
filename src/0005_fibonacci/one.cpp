#include "problem.h"

#include <iostream>
#include <fstream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

long fibonacci(int i) {
	if (i == 1)
		return 1;

	if (i == 2)
		return 1;

	return fibonacci(i - 1) + fibonacci(i - 2);
}

void Problem::Run(istream& input, ostream& output) {
	int i;
	
	input >> i;
	while (i != 0) {
		output << fibonacci(i) << endl;
		input >> i;
	}
}
