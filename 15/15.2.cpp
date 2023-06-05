#include <iostream>
#include <vector>

int main(){

 std::vector<int> vec = {2, 7, 11, 15};
    int x;
    std::cout << "X: ";
    std::cin >> x;


    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i] > x) 
            continue;
        for (int j = i + 1; j < vec.size(); ++j) {   
            if ((vec[i] + vec[j]) == x) {
                std::cout << vec[i] << " " << vec[j];
                return 0;
            }
        }
    }
    
}