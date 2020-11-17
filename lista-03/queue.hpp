#pragma once

#include "../lista-02/linked_list.hpp"

template<typename T>
class queue {
public:
	queue() {}

	~queue() {}

	void push(const T& data) {
		_list.push_back(data);
	}

	T pop() {
		return _list.pop();
	}

	T head() {
		return _list.head->data;
	}
	
	bool is_empty() {
		return _list.is_empty();
	}

	int size() {
		return _list.size();
	}

	void print() {
		return _list.print();
	}

private:

	linked_list<T> _list;
};
