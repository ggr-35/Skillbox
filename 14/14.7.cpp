#include <iostream>

void start_world(bool w[][4][4]){
    for (int k = 0; k < 10; k++){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                w[k][i][j] = false;
            }
        }
   }

}

void print_world(bool w[][4][4]){
    for (int k = 0; k < 10; k++){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
               std::cout << w[k][i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
   }
}

void input_word(bool w[][4][4], int height[][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << "h" << i << j << "= ";
            int x;
            std::cin >> x;
            height[i][j] = x;
        }
   }
   
   for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < height[i][j]; k++){
                w[k][i][j] = true;
            }
        }
   }
}

void output_level(bool w[][4][4], int level){
for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << w[level][i][j];
        }
        std::cout << std::endl;
    }
}



int main(){
    
   bool minecraft[10][4][4];
   int matrix_of_heights[4][4];
   start_world(minecraft);
   input_word(minecraft,matrix_of_heights);
   print_world(minecraft);
   
    while (true){
    int level;
    std::cout << "Enter the level: ";
    std::cin >> level;

    while (level < 0 || level > 9){
    std::cout << "Enter the level: ";
    std::cin >> level;
   }
    output_level(minecraft,level);
   }
}