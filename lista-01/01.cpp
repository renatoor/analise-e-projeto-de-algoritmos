#include <vector>
#include <iostream>

void print_primes(int n, std::vector<bool> &numbers) {
	int count = 1;

	std::cout << "Imprimindo números primos até " << n << ":" << std::endl;

	for (auto is_prime : numbers) {
		if (is_prime)
			std::cout << count << std::endl;

		count++;
	}
}

int main(int argc, char **argv) {
	int n;

	std::cout << "Digite um número maior que 0: ";
	std::cin >> n;

	if (n <= 0) {
		std::cerr << "Número menor ou igual a 0." << std::endl;
		return -1;
	}

	std::vector<bool> numbers(n, true);

	for (int i = 2; i <= n; i++) {
		for (int j = i * i; j <= n; j += i) {
			numbers[j - 1] = false;
		}
	}

	print_primes(n, numbers);

	return 0;
}
