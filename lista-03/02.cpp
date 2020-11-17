#include "queue.hpp"

#include <iostream>

int main(int argc, char **argv) {
	queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	queue.push(6);
	queue.push(7);
	queue.push(8);
	queue.push(9);
	queue.push(10);

	while (!queue.is_empty()) {
		int value = queue.pop();

		std::cout << value << std::endl;
	}

	return 0;
}
