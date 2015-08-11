#include "problem.h"

#include <iostream>
#include <fstream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

long fibonacci(int n) {
	int a = 0, b = 1, c = 1, x = 0;
	for (int i = 3; i <= n; i++) {
		x = c + b;
		a = b;
		b = c;
		c = x;
	}
	return c;
}

void Problem::Run(istream& input, ostream& output) {
	int i;
	
	input >> i;
	while (i != 0) {
		output << dec << fibonacci(i) << endl;
		input >> i;
	}
}
