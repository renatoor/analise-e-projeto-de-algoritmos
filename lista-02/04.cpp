#include <stdlib.h>
#include <iostream>
#include <string>

#include "linked_list.hpp"

bool balanced_parenthesis(std::string& input) {
	linked_list<char> list;

	bool is_balanced = true;

	for (auto &c : input) {
		switch (c) {
			case '(':
				list.push(c);
				break;
			case ')':
				if (list.is_empty())
					is_balanced = false;
				else
					list.pop();

				break;
			default:
				std::cerr << "A sequência possui caracteres que não são parênteses." << std::endl;
				exit(EXIT_FAILURE);
		}
	}

	if (!list.is_empty())
		is_balanced = false;

	return is_balanced;
}

int main(int argc, char** argv) {
	std::string input;

	std::cout << "Digite a sequência de parênteses: ";
	std::cin >> input;

	if (balanced_parenthesis(input)) {
		std::cout << "A string \"" << input << "\" está balanceada." << std::endl;
	}
	else {
		std::cout << "A string \"" << input << "\" não está balanceada." << std::endl;
	}

	return 0;
}
