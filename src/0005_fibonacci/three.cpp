#include "problem.h"

#include <iostream>
#include <fstream>
#include <math.h>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

long fibonacci(int n) {
	if (n == 1 || n == 2)
		return 1;
	if (n == 3)
		return 2;

	return (pow((1+sqrt(5.0))/2,n)-pow((1-sqrt(5.0))/2,n))/sqrt(5.0);
}

void Problem::Run(istream& input, ostream& output) {
	int i;
	
	input >> i;
	while (i != 0) {
		output << fibonacci(i) << endl;
		input >> i;
	}
}
