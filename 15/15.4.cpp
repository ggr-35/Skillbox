#include <iostream>
#include <vector>
#include <math.h>


int main() {
    std::vector<int> vec;
    vec.resize(6);
    for (int i = 0; i < vec.size(); i++)
    {
       int x;
       std::cin >> x;
       vec[i] = x;
    }
    
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size() - 1 - i; j++){
            if(fabs(vec[j]) > fabs(vec[j + 1])){
                int buf = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = buf;
            }
        }
    } 

    for (int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }

}