#include "tree.hpp"

#include <iostream>

bool compare_tree(tree_node<int> *node1, tree_node<int> *node2) {
	if (node1 == nullptr && node2 == nullptr) {
		return true;
	}	
	else if (node1 != nullptr && node2 != nullptr) {
		return compare_tree(node1->left, node2->left) && compare_tree(node1->right, node2->right);
	}

	return false;
}

int main(int argc, char **argv) {
	tree<int> tree1, tree2;

	tree1.insert(4);
	tree1.insert(2);
	tree1.insert(1);
	tree1.insert(3);
	tree1.insert(6);
	tree1.insert(5);
	tree1.insert(7);

	tree2.insert(4);
	tree2.insert(2);
	tree2.insert(1);
	tree2.insert(3);
	tree2.insert(6);
	tree2.insert(5);
	tree2.insert(7);

	std::cout << compare_tree(tree1.head, tree2.head) << std::endl;

	return 0;
}
