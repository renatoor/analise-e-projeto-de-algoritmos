#include "linked_list.hpp"

void reverse_list(linked_list<int>& list) {
	list_node<int> *node, *prev, *next;

	node = list.head;
	prev = nullptr;
	next = nullptr;

	list.tail = node;

	while (node != nullptr) {
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	list.head = prev;
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

	reverse_list(list);

	list.print();

	return 0;
}
