#include <iostream>
#include <unistd.h>
#include <vector>

const char *progname;

void usage() {
	std::cerr << "Busca binária não recursiva: " << progname << " -b" << std::endl;
	std::cerr << "Busca binária recursiva: " << progname << " -r" << std::endl;

	exit(EXIT_FAILURE);
}

int bin_search(std::vector<int> &vec, int value) {
	int low = 0;
	int high = vec.size();

	while (low <= high) {
		int mid = (low + high) >> 1;

		if (vec[mid] == value) return mid;
		else if (vec[mid] < value) low = mid + 1;
		else high = mid - 1;
	}

	return -1;
}

int rec_bin_search(std::vector<int> &vec, int low, int high, int value) {
	if (low <= high) {
		int mid = (low + high) >> 1;

		if (vec[mid] == value) return mid;
		else if (vec[mid] < value) return rec_bin_search(vec, mid + 1, high, value);
		else return rec_bin_search(vec, low, mid - 1, value);
	}

	return -1;
}

int main(int argc, char** argv) {
	char opt;
	int num;

	progname = argv[0];

	if (argc != 2) usage();

	int index;
	std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	while ((opt = getopt(argc, argv, "br")) != -1) {
		switch (opt) {
			case 'b':
				index = bin_search(vec, 9);
				break;
			case 'r':
				index = rec_bin_search(vec, 0, vec.size(), 15);
				break;
			default:
				usage();
		}
	}

	if (index == -1) std::cout << "Valor não encontrado." << std::endl;
	else std::cout << "Valor encontrado na posição: " << index << std::endl;

	return 0;
}
