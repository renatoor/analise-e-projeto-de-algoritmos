#pragma once

template<typename T>
class tree_node;

template<typename T>
class tree_node {
public:

	tree_node(const T& data) : data(data) {}

	~tree_node() {}

	T data;
	tree_node<T> *left = nullptr;
	tree_node<T> *right = nullptr;

};

template<typename T>
class tree {
public:

	tree() : _size(0) {}

	~tree() {
		destroy(head);
	}

	void insert(const T &data) {
		if (head == nullptr) {
			head = new tree_node<T>(data);
		}
		else {
			insert(head, data);
		}
		
		_size++;
	}

	tree_node<T> *search(const T &data) {
		return search(head, data);
	}

	int size() {
		return _size;
	}

	tree_node<T> *head = nullptr;

private:

	void insert(tree_node<T> *node, const T &data) {
		if (data < node->data) {
			if (node->left == nullptr) {
				node->left = new tree_node<T>(data);
			}
			else {
				insert(node->left, data);
			}
		}
		else {
			if (node->right == nullptr) {
				node->right = new tree_node<T>(data);
			}
			else {
				insert(node->right, data);
			}
		}
	}

	tree_node<T> *search(tree_node<T> *node, const T &data) {
		if (node == nullptr) {
			return nullptr;
		}
		else if (data == node->data) {
			return node;
		}
		else if (data < node->data) {
			return search(node->left, data);
		}
		else {
			return search(node->right, data);
		}
	}

	void destroy(tree_node<T> *node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			
			delete node;
		}
	}

	int _size;
};
