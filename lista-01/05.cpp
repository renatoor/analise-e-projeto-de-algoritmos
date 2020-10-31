#include <iostream>
#include <vector>

bool check_matrix(std::vector<std::vector<int>> &matrix) {
	int n = matrix.size();

	for (int i = 0; i < n; i++) {
		int row_sum = 0;
		int col_sum = 0;

		for (int j = 0; j < n; j++) {
			row_sum += matrix[i][j];
			col_sum += matrix[j][i];
		}

		if (col_sum != 1 || row_sum != 1)
			return false;
	}

	return true;
}

int main(int argc, char **argv) {
	std::vector<std::vector<int>> matrix {
		{1, 0, 0},
		{0, 0, 1},
		{0, 1, 0}
	};

	std::cout << "Matrix é de permutação: " << (check_matrix(matrix) ? "Sim" : "Não") << std::endl;

	return 0;
}
