#include <iostream>

void swap(int* x, int* y){
    int buf = *x;
    *x = *y;
    *y = buf;
}

void convers_and_print(int* x){
     
    for (int i = 0; i < 5; ++i)
    {
        swap((x + i),(x + 9 - i));
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << *(x + i) << " ";
    }

}




int main() {
  
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    convers_and_print(x);

}