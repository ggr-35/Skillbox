#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec,int* x){

    std::vector<int> buf;
    
    for(int i = 0; i < vec.size(); ++i){
      buf.push_back(vec[i]);
      vec[i] = *(x + i);
      *(x + i) = buf[i];
    }
}


int main() {
  
 std::vector<int> a = {1,2,3,4};
  
 int b[] = {2,4,6,8};
  
for(int i = 0; i < 4; ++i)
   std::cout << a[i];
std::cout << std::endl;
  
for(int i = 0; i < 4; ++i)
   std::cout << b[i];
std::cout << std::endl;


if(a.size() == (sizeof(b)/sizeof(*b)))
  swapvec(a,b);
else
  std::cerr << "Size mismatch" << std::endl;
  
for(int i = 0; i < 4; ++i)
   std::cout << a[i];
std::cout << std::endl;

for(int i = 0; i < 4; ++i)
   std::cout << b[i];

}