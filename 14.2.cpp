#include <iostream>

void output(char field[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << field[i][j];
    }
    std::cout << std::endl;
  }
}

void preparation(char field[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      field[i][j] = '-';
    }
  }
}

int main() {
  char game_field[3][3];
  preparation(game_field);
  char gamer_name = 'X';

  for (int i = 0; i < 9; ++i) {

    int x, y;
    std::cout << "turn: " << gamer_name;
    std::cout << " x,y:\n";
    std::cin >> x >> y;

    if (game_field[x][y] == '-') {

      game_field[x][y] = gamer_name;
      (gamer_name == 'X') ? (gamer_name = 'O') : (gamer_name = 'X');

      output(game_field);
      for (int step = 0; step < 2; ++step) {
        for (int i = 0; i < 3; ++i) {
          std::string str;
          for (int j = 0; j < 3; ++j) {
            str += game_field[i][j];
            if (str == "XXX") {
              std::cout << "X won";
              return 0;
            } else if (str == "OOO") {
              std::cout << "Y won";
              return 0;
            }
          }
        }
        int k = 1;
        for (int i = 0; i < 2; ++i) {
          for (int j = k; j < 3; ++j) {
            char buf = game_field[i][j];
            game_field[i][j] = game_field[j][i];
            game_field[j][i] = buf;
          }
          ++k;
        }
      }

    } else {
      std::cout << "Error, try again !\n";
      continue;
    }
  }
  std::cout << "Draw !";
}