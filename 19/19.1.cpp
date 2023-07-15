#include <iostream>
#include <fstream>


int main(){

    
    std::cout << "Enter your file location: ";
    std::string file_loc;
    std::cin >> file_loc;
    std::ifstream user_file;
    user_file.open(file_loc);

    while (!user_file.is_open())
    {
    std::cerr << "File oper error!" << std::endl;
    std::cout << "Enter your file location: ";
    std::string file_loc;
    std::cin >> file_loc;
    user_file.open(file_loc);
    }

    std::cout << "Enter the search word: ";
    std::string search_word;
    std::cin >> search_word;

    int cout = 0;

    while (!user_file.eof())
    {
        std::string word;
        user_file >> word;

        if(word == search_word)
            ++cout;
    }

    std::cout << cout << std::endl;
    user_file.close();


}