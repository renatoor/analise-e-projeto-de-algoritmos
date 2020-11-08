#include "linked_list.hpp"

void swap_smallest(linked_list<int>& list) {
	list_node<int> *prev, *smallest_prev, *smallest_next, *smallest_node;

	prev = nullptr;
	smallest_prev = nullptr;
	smallest_next = nullptr;
	smallest_node = nullptr;

	for (auto node = list.head; node != nullptr; node = node->next) {
		if (!smallest_node || node->data < smallest_node->data) {
			smallest_prev = prev;
			smallest_next = node->next;
			smallest_node = node;
		}

		prev = node;
	}

	if (smallest_node == list.head)
		return;

	smallest_prev->next = smallest_next;
	smallest_node->next = list.head;
	list.head = smallest_node;
}

int main(int argc, char** argv) {
	linked_list<int> list;

	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(1);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);
	list.push_back(10);

	swap_smallest(list);

	list.print();

	return 0;
}
