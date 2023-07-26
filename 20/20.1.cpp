#include <iostream>
#include <fstream>


int main(){

    std::ofstream file("/Users/german/Downloads/test.txt",std::ios::app);

    if(!file.is_open())
        return 1;

    std::string f_name, l_name, date;
    int money;
    bool stop = true;

        while (stop)
        {
        std::cout << "Enter a new entry in the format (name lastname date money): ";
        std::cin >> f_name >> l_name >> date >> money;

        if(std::stoi(date.substr(3, 2)) < 1 || std::stoi(date.substr(3, 2)) > 12)
            std::cerr << "Date error (month) !" << std::endl;

        if(std::stoi(date.substr(0, 2)) < 1 || std::stoi(date.substr(0, 2)) > 31)
            std::cerr << "Date error (day) !" << std::endl;

        if(std::stoi(date.substr(6, 4)) < 1950 || std::stoi(date.substr(6, 4)) > 2023)
            std::cerr << "Date error (year) !" << std::endl;

            while (std::stoi(date.substr(3, 2)) < 1 || std::stoi(date.substr(3, 2)) > 12
                    || std::stoi(date.substr(0, 2)) < 1 || std::stoi(date.substr(0, 2)) > 31
                    || std::stoi(date.substr(6, 4)) < 1950 || std::stoi(date.substr(6, 4)) > 2023)
            {
                std::cout << "Enter a new entry in the format (name lastname date money): ";
                std::cin >> f_name >> l_name >> date >> money;
            }

        file << f_name << " " << l_name << " " << date << " " << money << std::endl;
        std::cout << "Do you wont to make a new entry ?(YES - 1 / N0 - 0): ";
        std::cin >> stop;
        }
        
    file.close();
}