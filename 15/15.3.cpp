#include <iostream>
#include <vector>


void fifth_order(std::vector<int> vec){

    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size() - 1 - i; j++){
            if(vec[j] > vec[j + 1]){
                int buf = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = buf;
            }
        }
    }  
    std::cout << vec[4] << std::endl;
}





int main() {


std::vector<int> vec;

while (true){
   int x;
   std::cin >> x;
   if (x == -1)
     fifth_order(vec);
   else if (x == -2)
     break;
   else 
     vec.push_back(x);
}

   










}