#include "problem.h"

#include <iostream>
#include <fstream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void Problem::Run(istream& input, ostream& output) {
	int a = 0;

	input >> a;
	while (a != 0) {
		output << hex << uppercase << a << endl;
		input >> a;
	}
}

