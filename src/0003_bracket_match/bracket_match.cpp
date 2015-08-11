#include "problem.h"

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

void Problem::Run(istream& input, ostream& output) {
	string line;

	getline(input, line);
	while (input.good() && line.length() > 0) {
		bool ok(true);
		stack<char> stack;
		
		for (unsigned int i = 0; i < line.length(); i++) {
			char c = line[i];
			switch (c) {
				case '(':
				case '[':
				case '{':
					stack.push(c);
					break;
				case ')':
					if (stack.empty() || stack.top() != '(') {
						ok = false;
						break;
					}
					stack.pop();
					break;
				case ']':
					if (stack.empty() || stack.top() != '[') {
						ok = false;
						break;
					}
					stack.pop();
					break;
				case '}':
					if (stack.empty() || stack.top() != '{') {
						ok = false;
						break;
					}
					stack.pop();
					break;
			}
		}
		if (!stack.empty())
			ok = false;

		output << ok << endl;

		getline(input, line);
	}
}

