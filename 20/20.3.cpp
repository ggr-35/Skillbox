#include <iostream>
#include <fstream>


int main(){

    std::ifstream file_river("/Users/german/Downloads/test.txt");
    std::ofstream file_basket("/Users/german/Downloads/basket.txt",std::ios::app);

    if(!file_river.is_open() || !file_basket.is_open())
        return 1;

    bool stoper = true;

    while (stoper)
    {
    std::cout << "What kind of fish will you catch now ? : ";
    std::string search, found;
    std::cin >> search;
    int count = 0;
 
        while (!file_river.eof())
        {

        file_river >> found;
        
        if(search == found)
        {
            file_basket << found << std::endl;
            ++count;
        }

        }

        std::cout << "Total: " << count << std::endl;
    
        std::cout << "Do you want to try again ? (YES - 1 / N0 - 0): ";
        std::cin >> stoper;
        file_river.seekg(0);

    }
    
    file_river.close();
    file_basket.close();
}