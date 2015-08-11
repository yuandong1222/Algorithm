#include "problem.h"

#include <iostream>
#include <stack>
#include <string>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

class Position {
	public:

		Position(int row_index, int column_index) {
			_row_index = row_index;
			_column_index = column_index;
		}

		Position* next(Position* adjacent_position) const {
			if (adjacent_position == NULL)
				return new Position(_row_index - 1, _column_index);
			if (adjacent_position -> _row_index == _row_index - 1)
				return new Position(_row_index, _column_index + 1);
			if (adjacent_position -> _row_index == _row_index + 1)
				return new Position(_row_index, _column_index - 1);
			if (adjacent_position -> _column_index == _column_index + 1)
				return new Position(_row_index + 1, _column_index);
			return NULL;
		}

		bool operator==(const Position& position) const {
			return _row_index == position._row_index
				&& _column_index == position._column_index;
		}

		int get_row_index() const {
			return _row_index;
		}
		int get_column_index() const {
			return _column_index;
		}

	private:
		int _row_index;
		int _column_index;
};

int* maze = NULL;
int row_length, column_length;
Position *start_position, *end_position;
stack<Position*> path;

void construct_maze(istream& input) {
	input >> row_length >> column_length;

	maze = new int[row_length * column_length];

	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < column_length; j++) {
			input >> maze[i * row_length + j];
			maze[i * row_length + j]--;
		}
	}

	int row_index, column_index;
	char c;
	input >> row_index >> c >> column_index;
	start_position = new Position(row_index, column_index);
	input >> row_index >> c >> column_index;
	end_position = new Position(row_index, column_index);
}
void destory_maze() {
	row_length = column_length = 0;

	delete [] maze;
	maze = NULL;

	delete start_position;
	start_position = NULL;
	
	delete end_position;
	end_position = NULL;
}

int get_value(Position* position) {
	return maze[position -> get_row_index() * row_length + position -> get_column_index()];
}
void mark_position(Position* position, int value) {
	maze[position -> get_row_index() * row_length + position -> get_column_index()] = value;
}
bool can_pass(Position* last_position, Position* current_position) {
	if (get_value(current_position) == 0)
		return true;

	if (get_value(current_position) == -1)
		return false;

	return (get_value(last_position) + 1 < get_value(current_position));
}

void assign_path(stack<Position*>& s) {
	stack<Position*> temp;
	
	while (!path.empty()) {
		delete path.top();
		path.pop();
	}

	while (!s.empty()) {
		Position* p = s.top();
		path.push(new Position(p -> get_row_index(), p -> get_column_index()));
		temp.push(p);
		s.pop();
	}
	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}
}

void find_path(stack<Position*>& stack) {
	Position* last_position = stack.top();
	if (*last_position == *end_position) {
		if (path.size() == 0 || stack.size() < path.size()) {
			assign_path(stack);
			return;
		}
	}

	Position* current_position = last_position -> next(NULL);
	while (current_position != NULL) {
		if (can_pass(last_position, current_position)){
			stack.push(current_position);
			mark_position(current_position, get_value(last_position) + 1);

			find_path(stack);

			stack.pop();
		}
		Position* temp = current_position;
		current_position = last_position -> next(current_position);
		delete temp;
	}

	return;
}
void print_path(ostream& output) {
	while (!path.empty()) {
		Position *p = path.top();

		output << p -> get_row_index() << ',' << p -> get_column_index();
		if (path.size() > 1)
			output << ' ';

		delete p;
		path.pop();
	}
	output << endl;
}

void Problem::Run(istream& input, ostream& output) {
	stack<Position*> stack;

	construct_maze(input);

	stack.push(start_position);
	mark_position(start_position, 1);
	find_path(stack);

	print_path(output);

	destory_maze();
}	

