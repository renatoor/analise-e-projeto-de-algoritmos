#pragma once

#include <iostream>

template<typename T>
class list_node;

template<typename T>
class list_node {
public:
	list_node(const T& data) : data(data) {}

	~list_node() {}

	T data;
	list_node<T> *next = nullptr;
};


template<typename T>
class linked_list {
public:
	linked_list() : _size(0) {}

	~linked_list() {
		list_node<T> *tmp, *node;

		node = this->head;

		while (node != nullptr) {
			tmp = node;
			node = tmp->next;

			delete tmp;
		}
	}

	void push(const T& data) {
		list_node<T> *new_node = new list_node<T>(data);

		if (this->head) {
			new_node->next = this->head;
		}

		if (!this->tail) {
			this->tail = new_node;
		}

		this->head = new_node;

		_size++;
	}

	void push_back(const T& data) {
		list_node<T> *new_node = new list_node<T>(data);

		if (this->tail) {
			this->tail->next = new_node;
		}

		if (!this->head) {
			this->head = new_node;
		}

		this->tail = new_node;

		_size++;
	}

	T pop() {
		list_node<T> *node = this->head;

		T value = node->data;

		this->head = node->next;

		delete node;

		_size--;

		return value;
	}
	
	bool is_empty() {
		return this->head ? false : true;
	}

	int size() {
		return _size;
	}

	void print() {
		int position = 0;

		for (auto node = this->head; node != nullptr; node = node->next) {
			std::cout << "linked_list[" << position << "] " << node->data << std::endl;
			position++;
		}
	}

	list_node<T> *head = nullptr;
	list_node<T> *tail = nullptr;

private:

	int _size;
};
