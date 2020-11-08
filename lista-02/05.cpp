#include <stdlib.h>
#include <vector>
#include <iostream>

template<typename T>
class double_stack {
public:

	double_stack(size_t size) :
		_stack(size),
	   	_left_index(0),
	   	_right_index(size - 1) {}

	void push_left(const T& value) {
		if (_left_index > _right_index) {
			std::cerr << "Estouro de pilha." << std::endl;
			exit(EXIT_FAILURE);
		}

		_stack[_left_index++] = value;
	}

	T pop_left() {
		if (_left_index == 0) {
			std::cerr << "Estouro de pilha." << std::endl;
			exit(EXIT_FAILURE);
		}

		return _stack[--_left_index];
	}

	void push_right(const T& value) {
		if (_right_index < _left_index) {
			std::cerr << "Estouro de pilha." << std::endl;
			exit(EXIT_FAILURE);
		}

		_stack[_right_index--] = value;
	}

	T pop_right() {
		if (_right_index == _stack.size() - 1) {
			std::cerr << "Estouro de pilha." << std::endl;
			exit(EXIT_FAILURE);
		}

		return _stack[++_right_index];
	}

	void print() {
		for (int i = 0; i < _stack.size(); i++) {
			if (i >= _left_index && i <= _right_index)
				std::cout << "double_stack[" << i << "]: empty" << std::endl;
			else
				std::cout << "double_stack[" << i << "]: " << _stack[i] << std::endl;
		}
	}

private:

	std::vector<T> _stack;
	int _left_index;
	int _right_index;
};

int main(int argc, char **argv) {
	double_stack<int> stack (10);

	stack.push_left(1);
	stack.push_left(2);
	stack.push_left(3);
	stack.push_left(4);
	stack.push_left(5);
	stack.push_right(6);
	stack.push_right(7);
	stack.push_right(8);
	stack.push_right(9);
	stack.push_right(10);

	stack.print();

	return 0;
}
