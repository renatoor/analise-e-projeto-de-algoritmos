#include <stdlib.h>

#include "linked_list.hpp"

void swap(linked_list<int>& list, int index_a, int index_b) {
	list_node<int> *prev, *prev_a, *a, *next_a, *prev_b, *b, *next_b;
	int position = 0;

	prev = nullptr;

	prev_a = nullptr;
	a = nullptr;
	next_a = nullptr;

	prev_b = nullptr;
	b = nullptr;
	next_b = nullptr;

	for (auto node = list.head; node != nullptr; node = node->next) {
		if (position == index_a) {
			prev_a = prev;
			a = node;
			next_a = node->next;
		}

		if (position == index_b) {
			prev_b = prev;
			b = node;
			next_b = node->next;
		}

		if (a != nullptr && b != nullptr)
			break;

		prev = node;
		position++;
	}

	if (a == nullptr || b == nullptr) {
		std::cerr << "Índices invalidos, elemento não encontrado." << std::endl;
		exit(EXIT_FAILURE);
	}

	if (prev_a)
		prev_a->next = b;
	else
		list.head = b;

	b->next = next_a;

	if (prev_b)
		prev_b->next = a;
	else
		list.head = a;

	a->next = next_b;
}

int main(int argc, char** argv) {
	linked_list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);
	list.push_back(10);

	swap(list, 2, 9);

	list.print();

	return 0;
}
