#include <iostream>

bool matrix_comparison(int m_1[][4], int m_2[][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (m_1[i][j] != m_2[i][j]) {
        std::cout << "The matrices are not equal";
        return false;
      }
    }
  }
  return true;
}

void print_matrix(int matrix[][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
}

void matrix_input(int matrix[][4]) {
  int x;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << "x" << i + 1 << j + 1 << "= ";
      std::cin >> x;
      matrix[i][j] = x;
    }
  }
}

void conversion_to_diagonal(int matrix[][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i != j) {
        matrix[i][j] = 0;
      }
    }
  }
}

int main() {

  int a[4][4];
  int b[4][4];
  std::cout << "matrix_1 = \n";
  matrix_input(a);
  std::cout << "matrix_2 = \n";
  matrix_input(b);
  if (matrix_comparison(a, b)) {
    conversion_to_diagonal(a);
    print_matrix(a);
  }
}
