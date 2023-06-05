#include <iostream>
#include <math.h>

int a[5][5];

int number = 0;



int main() {
    int start;
    for(int i = 0; i < 5; ++i){
    
        for(int j = 0; j < 5; ++j){
            std::cout << (a[i][j] = number);
            start = j;
            ++number;
        }
            std::cout << std::endl;
    }
}