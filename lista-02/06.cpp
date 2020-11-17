#include <sstream>
#include <iostream>
#include <string>

#include "linked_list.hpp"

class car {
public:

	car(std::string& plate) : _plate(plate), _maneuvers(0) {}

	~car() {};

	std::string plate() const {
		return _plate;
	}

	int maneuvers() const {
		return _maneuvers;
	}

	void inc_maneuvers() {
		_maneuvers++;
	}

private:

	std::string _plate;
	int _maneuvers;
};

std::ostream& operator<<(std::ostream& outs, const car& c)
{
	return outs << "Carro[" << c.plate() << "]: " << c.maneuvers() << " manobras";
}

void park_car(linked_list<car> &list, std::string plate) {
	for (auto node = list.head; node != nullptr; node = node->next) {
		if (node->data.plate() == plate) {
			std::cerr << "Carro já estacionado." << std::endl;
			return;
		}
	}

	car c(plate);

	list.push(c);
}

void remove_car(linked_list<car> &list, std::string plate) {
	linked_list<car> aux_list;

	bool found = false;

	while (!list.is_empty()) {
		car c = list.pop();

		if (c.plate() == plate) {
			std::cout << c << std::endl;
			found = true;
			break;
		}

		aux_list.push(c);
	}

	if (!found) {
		std::cerr << "Carro " << plate << " não está estacionado." << std::endl;
	}

	while (!aux_list.is_empty()) {
		car c = aux_list.pop();
		if (found) c.inc_maneuvers();
		list.push(c);
	}
}

int main(int argc, char** argv) {
	char action;
	std::string input, plate;

	linked_list<car> list;

	while (true) {
		std::cout << "Digite o comando: ";
		std::getline(std::cin, input);

		std::istringstream iss(input);

		iss >> action >> plate;

		switch (action) {
			case 'E':
				if (list.size() == 10)
					std::cout << "Estacionamento cheio." << std::endl;
				else
					park_car(list, plate);

				break;
			case 'S':
				remove_car(list, plate);

				break;
			case 'p':
				std::cout << "ESTACIONAMENTO:" << std::endl;
				list.print();

				break;
			default:
				std::cerr << "Comando inválido." << std::endl;
		}
	}

	return 0;
}
