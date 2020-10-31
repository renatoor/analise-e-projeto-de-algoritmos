#include <iostream>
#include <unistd.h>
#include <vector>

const char *progname;

void usage() {
	std::cerr << "Converter para binário: " << progname << " -d <decimal>" << std::endl;
	std::cerr << "Converter para decimal: " << progname << " -b <binário>" << std::endl;

	exit(EXIT_FAILURE);
}

void convert_to_dec(int num) {
	int digit;
	int base = 1;
	int value = 0;

	while (num) {
		digit = num % 10;

		value += digit * base;

		num /= 10;
		base *= 2;
	}

	std::cout << "Decimal: " << value << std::endl;
}

void convert_to_bin(int num) {
	std::vector<int> bin_num(32, 0);

	int i = 0;

	while (num > 0) {
		bin_num[i] = num % 2;
		num /= 2;
		i++;
	}

	bool right_zero = true;

	for (int i = 31; i >= 0; i--) {
		if (bin_num[i] == 0 && right_zero) continue;
		else right_zero = false;

		std::cout << bin_num[i];
	}

	std::cout << std::endl;
}

int main(int argc, char** argv) {
	char opt;
	int num;

	progname = argv[0];

	if (argc != 3) usage();

	while ((opt = getopt(argc, argv, "b:d:")) != -1) {
		switch (opt) {
			case 'b':
				num = atoi(optarg);
				convert_to_dec(num);
				break;
			case 'd':
				num = atoi(optarg);
				convert_to_bin(num);
				break;
			default:
				usage();
		}
	}

	return 0;
}
