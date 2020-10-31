#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

int main(int argc, char **argv) {
	int n;
	std::string input;

	double zeros = 0.0;
	double positives = 0.0;
	double negatives = 0.0;

	std::cout << "Digite uma sequência de números: ";

	std::getline(std::cin, input);
	std::istringstream iss(input);

	std::vector<int> numbers {std::istream_iterator<int>{iss}, std::istream_iterator<int>{}};

	for (auto n : numbers) {
		if (n == 0) zeros++;
		else if (n > 0) positives++;
		else if (n < 0) negatives++;
	}

	std::cout << "Positivos: " << (positives / numbers.size() * 100) << std::endl;
	std::cout << "Negativos: " << (negatives / numbers.size() * 100) << std::endl;
	std::cout << "Zeros: " << (zeros / numbers.size() * 100) << std::endl;

	return 0;
}
