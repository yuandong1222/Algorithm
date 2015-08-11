#include "problem.h"

#include <iostream>

using namespace algorithm;
using namespace std;

void Problem::SetUp(istream& input, ostream& output) {}
void Problem::TearDown(istream& input, ostream& output) {}

struct Node {

	Node() {
		weight = 0;
		parent = 0;
		left_child = 0;
		right_child = 0;
	}

	int weight;
	int parent;
	int left_child;
	int right_child;
	string code;
};

Node *tree = NULL;
int node_count = 0;
int max_node_count = 0;

void construct_tree(istream& input) {
	input >> node_count;

	max_node_count = 2 * node_count - 1;
	tree = new Node[max_node_count];

	for (int i = 0; i < node_count; i++) {
		input >> tree[i].weight;
	}
}
void destory_tree() {
	delete [] tree;
}

void find_min(int* min_one, int* min_two) {
	Node *min_one_node = NULL;
	Node *min_two_node = NULL;

	for (int i = 0; i < max_node_count; i++) {
		Node *node = tree + i;
		if (node -> weight == 0)
			break;

		if (node -> parent != 0)
			continue;

		if (min_one_node == NULL || node -> weight < min_one_node -> weight) {
			*min_two = *min_one;
			min_two_node = min_one_node;

			*min_one = i;
			min_one_node = node;
		} else if (min_two_node == NULL || node -> weight < min_two_node -> weight) {
			min_two_node = node;
			*min_two = i;
		}
	}
}
void build_tree() {
	for (int i = node_count; i < max_node_count; i++) {
		int min_one, min_two;
		find_min(&min_one, &min_two);

		tree[min_one].parent = i;
		tree[min_two].parent = i;

		tree[i].weight = tree[min_one].weight + tree[min_two].weight;
		tree[i].left_child = min_one;
		tree[i].right_child = min_two;
	}
}

void build_code() {
	for (int i = 0; i < node_count; i++) {
		string *code = &(tree[i].code);
		Node *node = tree + i;
		while (node -> parent != 0) {
			if (node - tree == tree[node -> parent].left_child) 
				code -> insert(0, "0");
			else
				code -> insert(0, "1");

			node = tree + node -> parent;
		}
	}
}

void print_code(ostream& output) {
	for (int i = 0; i < node_count; i++) {
		output << tree[i].code << ' ';
	}
	output << endl;
}

void Problem::Run(istream& input, ostream& output) {
	construct_tree(input);
	build_tree();
	build_code();
	print_code(output);
	destory_tree();
}

