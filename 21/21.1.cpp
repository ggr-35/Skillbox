#include <iostream>
#include <fstream>
#include <vector>

struct person
{
    std::string name = "unknown";
    std::string surname = "unknown";
    std::string date = "00.00.0000";
    int payout_amount = 0;
};


void file_list()
{
    std::ifstream file_list("/Users/german/Downloads/game.txt", std::ios::binary);

    if(!file_list.is_open())
    {
        std::cerr << "File erro !" << std::endl;
        return;
    }


    std::vector<person> person_vec;
    person new_person;
    
    while (true)
    {  
        file_list >> new_person.name >> new_person.surname >> new_person.date >> new_person.payout_amount;
        if(file_list.eof())
            break;

        person_vec.push_back(new_person);
    }
    
    for (int i = 0; i < person_vec.size(); i++)
    {
       std::cout << person_vec[i].name << " " << person_vec[i].surname << " " << person_vec[i].date << " " << person_vec[i].payout_amount << std::endl;
    }

    file_list.close();
}



void file_add()
{
    std::ofstream file_save("/Users/german/Downloads/game.txt", std::ios::binary);
    if(!file_save.is_open())
    {
        std::cerr << "File erro !" << std::endl;
        return;
    }


    person new_person;
      
        std::cout << "Enter the name: ";
        std::cin >> new_person.name;

        std::cout << "Enter the surname: ";
        std::cin >> new_person.surname;

        std::cout << "Enter the date: ";
        std::cin >> new_person.date;

        std::cout << "Enter the payout_amount: ";
        std::cin >> new_person.payout_amount;

        file_save << new_person.name << " " << new_person.surname << " " << new_person.date << " " << new_person.payout_amount << std::endl;

    std::cout << "Add has successfully" << std::endl;
    file_save.close();
}


int main(){

    std::string command;

    while (true)
    {
        std::cout << "list or add ?: ";
        std::cin >> command;
        
        if(command == "list")
        {   
            file_list();
        }
        else if(command == "add")
        {
            file_add();
        }
        else
        {
            std::cerr << "Uncorrect command !";
            return 1;
        }
    }
}