#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Arquivo não especificado." << std::endl;
		return -1;
	}

	std::string filename (argv[1]);

	std::ifstream ifs(filename, std::ifstream::in);

	if (!ifs.is_open()) {
		std::cerr << "Falha ao abrir arquivo: " << filename << std::endl;
		return -1;
	}

	int count = 0;

	while (ifs.good()) {
		char c = ifs.get();

		switch (c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				count++;
				break;
			default:
				break;
		}
	}

	if (!ifs.eof() && ifs.fail()) {
		std::cerr << "Falha ao ler arquivo: " << filename << std::endl;
		return -1;
	}

	std::cout << "Número de vogais: " << count << std::endl;

	ifs.close();

	return 0;
}
