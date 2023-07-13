#include <iostream>



void swap(int* x, int* y){
    int buf = *x;
    *x = *y;
    *y = buf;
}

/*void swap_1(int* x, int* y){
    int* buf = x;
    x = y;
    y = buf;
}*/

int main() {

int a = 10;

int b = 20;

swap(&a,&b);
std::cout << a << " " << b;

// 20 10

}