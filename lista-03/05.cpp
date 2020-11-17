#include "tree.hpp"

#include <iostream>

bool is_strictly_binary(tree_node<int> *node) {
	if (node->left != nullptr && node->right != nullptr) {
		return is_strictly_binary(node->left) && is_strictly_binary(node->right);
	}
	else if (node->left == nullptr && node->right == nullptr) {
		return true;
	}

	return false;
}

bool is_complete(tree_node<int> *node, int index, int size) {
	if (node == nullptr) {
		return true;
	}
	else if (index >= size) {
		return false;
	}
	else {
		return is_complete(node->left, 2 * index + 1, size) && is_complete(node->right, 2 * index + 2, size);
	}
}

bool is_full_internal(tree_node<int> *node, int level, int &depth) {
	if (node->left == nullptr && node->right == nullptr) {
		if (depth == 0) {
			depth = level;
			return true;
		}

		return level == depth;
	}
	else if (node->left == nullptr || node->right == nullptr) {
		return false;
	}
	else {
		return is_full_internal(node->left, level + 1, depth) && is_full_internal(node->right, level + 1, depth);
	}
}

bool is_full(tree_node<int> *node) {
	int depth = 0;

	return is_full_internal(node, 0, depth);
}

int main(int argc, char **argv) {
	tree<int> tree;

	tree.insert(5);
	tree.insert(3);
	tree.insert(7);
	tree.insert(2);
	tree.insert(4);
	tree.insert(6);
	tree.insert(8);

	std::cout << is_strictly_binary(tree.head) << std::endl;;
	std::cout << is_complete(tree.head, 0, tree.size()) << std::endl;
	std::cout << is_full(tree.head) << std::endl;

	return 0;
}
