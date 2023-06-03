#include <iostream>

void input_matrix(double matrix[][4]) {
  int x;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << "X" << i + 1 << j + 1 << "= ";
      std::cin >> x;
      matrix[i][j] = x;
    }
  }
}

int main() {
  std::cout << "Enter the vector:" << std::endl;
  double b[4];
  for (int i = 0; i < 4; ++i) {
    std::cout << "b[" << i + 1 << "]= ";
    std::cin >> b[i];
  }
  std::cout << "Enter the matrix:" << std::endl;
  double a[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << "a[" << i + 1 << "][" << j + 1 << "]= ";
      std::cin >> a[i][j];
    }
  }
  
  double c[4];

  for (int i = 0; i < 4; ++i) {
    double buf = 0;
    for (int j = 0; j < 4; ++j) {
      buf += a[i][j] * b[i];
    }
    c[i] = buf;
  }

  std::cout << "vector'C' = ";
  for (int i = 0; i < 4; ++i) {
    std::cout << c[i] << " ";
  }
}