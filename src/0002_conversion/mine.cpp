#include "problem.h"

#include <iostream>
#include <fstream>
#include <stack>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void Problem::Run(istream& input, ostream& output) {
	int a = 0;

	input >> a;
	while (a != 0) {

		stack<int> stack;
		while(a) {
			stack.push(a % 16);
			a /= 16;
		}
		while(!stack.empty()) {
			a = stack.top();
			if (a <= 9 ) {
				output << a;
			} else {
				output << ((char)(a - 10 + 'A'));
			}
			stack.pop();
		}
		output << endl;

		input >> a;
	}
}

