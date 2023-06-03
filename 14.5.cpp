#include <iostream>

void input(bool matrix[][12]) {
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      matrix[i][j] = true;
    }
  }
}

void map(bool matrix[][12]) {
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      (matrix[i][j]) ? (std::cout << "O") : (std::cout << "X");
    }
    std::cout << std::endl;
  }
}

void print(bool matrix[][12]) {
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
}

void del(bool matrix[][12],int x1, int y1, int x2, int y2){
  if((x1 >= x2) && (y1 >= y2)){
    int buf_1 = x1;
    int buf_2 = y1;
    x1 = x2;
    y1 = y2;
    x2 = buf_1;
    y2 = buf_2;
  }
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if(matrix[i][j]){
            matrix[i][j] = false;
            std::cout << "Pop!\n";
            }
        }
    }
}

bool stop(bool matrix[][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
           if(matrix[i][j] != false)
           {
            return false;
           } 
        }
    }
    return true;
}


int main() {
  bool condition[12][12];
  input(condition);
  map(condition);
  int x1,y1,x2,y2;

while (!stop(condition))
{
  std::cout << "Enter the coordinates of the area\n";
  std::cout << "x1,y1,x2,y2: \n";
  std::cin >> x1 >> y1 >> x2 >> y2;

   if(x1 < 0 || x1 > 11 || y1 < 0 || y1 > 11 
     || x2 < 0 || x2 > 11 || y2 < 0 || y2 > 11){
        std::cout << "Error!\n";
        continue;
    }
    
     del(condition,x1,y1,x2,y2);
     map(condition);
}
}