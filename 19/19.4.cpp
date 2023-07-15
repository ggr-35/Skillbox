#include <iostream>
#include <fstream>
#include <vector>


int main(){
   
   std::cout << "Enter your file location: ";
    std::string file_loc;
    std::cin >> file_loc;
    std::ifstream user_file;
    user_file.open(file_loc);

   while (!user_file.is_open())
   {
    std::cerr << "Open file error!" << std::endl;
    std::cout << "Enter your file location: ";
    std::cin >> file_loc;
    user_file.open(file_loc);
   }

    std::string word;
  
     user_file >>  word;

    if(word[1] != 'P' || word[2] != 'N' || word[3] != 'G'){

        std::cout << "This is't a PNG file" << std::endl;
    }else
        std::cout << "This is a PNG file" << std::endl;

}