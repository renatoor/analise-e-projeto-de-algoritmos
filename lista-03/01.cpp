#include "stack.hpp"

#include <iostream>

template<typename T>
class list {
public:

	void push(const T& data) {
		_stack.push(data);
	}

	T pop() {
		while (!_stack.is_empty()) {
			T data = _stack.pop();
			_aux_stack.push(data);
		}
		
		T result = _aux_stack.pop();

		while (!_aux_stack.is_empty()) {
			T data = _aux_stack.pop();
			_stack.push(data);
		}

		return result;
	}

	bool is_empty() {
		return _stack.is_empty();
	}

private:

	stack<T> _stack;
	stack<T> _aux_stack;
};

int main() {
	list<int> list;

	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	list.push(5);
	list.push(6);
	list.push(7);
	list.push(8);
	list.push(9);
	list.push(10);

	while (!list.is_empty()) {
		int value = list.pop();

		std::cout << value << std::endl;
	}

	return 0;
}
