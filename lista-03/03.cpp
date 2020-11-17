#include "queue.hpp"

#include <string>

class plane {
public:

	plane(int id, std::string &name, std::string &from, std::string &to) : _id(id), _name(name), _from(from), _to(to) {}

	~plane() {}

	int id() const {
		return _id;
	}

	std::string name() const {
		return _name;
	}

	std::string from() const {
		return _from;
	}

	std::string to() const {
		return _to;
	}

private:

	int _id;
	std::string _name;
	std::string _from;
	std::string _to;

};

std::ostream& operator<<(std::ostream& outs, const plane& p)
{
	return outs << "Avião[" << p.id() << "], nome: " << p.name() << ", origem: " << p.from() << ", destino: " << p.to();
}

int main(int argc, char **argv) {
	int action;
	queue<plane> queue;

	int id;
	std::string name, from, to;

	while (true) {
		std::cout << "1) Listar o número de aviões esperando para decolar" << std::endl;
		std::cout << "2) Autorizar a decolagem do primeiro avião na fila" << std::endl;
		std::cout << "3) Adicionar um avião na fila de espera" << std::endl;
		std::cout << "4) Listar todos os aviões que estão na lista de espera" << std::endl;
		std::cout << "5) Listar as características do primeiro avião da fila" << std::endl;

		std::cout << "Digite o comando: ";
		std::cin >> action;

		switch (action) {
			case 1:
				std::cout << queue.size() << " aviões" << std::endl;

				break;
			case 2:
				queue.pop();

				break;
			case 3:
				std::cout << "Identificador: ";
				std::cin >> id;

				std::cout << "Nome: ";
				std::cin >> name;

				std::cout << "Origem: ";
				std::cin >> from;

				std::cout << "Destino: ";
				std::cin >> to;

				queue.push(plane(id, name, from, to));

				break;
			case 4:
				queue.print();

				break;
			case 5:
				std::cout << queue.head() << std::endl;

				break;
		}
	}

	return 0;
}
