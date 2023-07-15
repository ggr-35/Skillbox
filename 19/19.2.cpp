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
    
    std::vector<std::string> text;
    std::string word;
    
    while (!user_file.eof())
    {
        std::getline(user_file, word);
        text.push_back(word);
    }

    for (int i = 0; i < text.size(); i++)
    {
        std::cout << text[i] << std::endl;
    }
    
    
    
    
    




}