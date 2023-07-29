#include <iostream>
#include <map>

enum command_types
{
    add_to,
    ph_search,
    searc_last_name,
};


void add(std::map<std::string, std::string>& phone_dir)
{
    std::string ph_str, last_n_str;
    std::cout << "Enter the pone number and last name: "; std::cin >> ph_str >> last_n_str;
    phone_dir.insert(std::make_pair<std::string, std::string>(ph_str, last_n_str));
}

void phone_search(std::map<std::string, std::string> phone_dir)
{   
    std::string ph_str;
    std::cout << "Enter the phone search: "; std::cin >> ph_str;
    std::map<std::string, std::string>::iterator f_it = phone_dir.find(ph_str);
    if (f_it != phone_dir.end())
        std::cout << "Search successful: " << f_it->first << " " << f_it->second << std::endl;
    else
        std::cout << "Search don,t successful" << std::endl;
}

bool ln_search(std::map<std::string, std::string> phone_dir)
{   
    std::string last_n_str;
    bool result = false;
    std::cout << "Enter the lanst name to search: "; std::cin >> last_n_str;
    std::map<std::string, std::string>::iterator it;
   
        for (it = phone_dir.begin(); it != phone_dir.end() ; it++)
        {
            if(it->second == last_n_str)
            {
                std::cout << it->first << " ";
                result = true;
            }

        }
        std::cout << std::endl;
        return result;
}



int main()
{
    std::map<std::string, std::string> phone_dir;
    phone_dir.insert(std::make_pair<std::string, std::string>("69-70-30", "Ivanov"));
    phone_dir.insert(std::make_pair<std::string, std::string>("11-11-11", "Petrov"));
    phone_dir.insert(std::make_pair<std::string, std::string>("12-12-12", "Petrov"));
    phone_dir.insert(std::make_pair<std::string, std::string>("11-42-34", "Fedorov"));
    int command;

    std::cout << "Enter the command(1 - add / 2 - phone search / 3 - search by last name): "; std::cin >> command;
    

    while (command < 1 || command > 3)
    {   
        std::cout << "Command error!" << std::endl;
        std::cout << "Enter the command(1 - add / 2 - phone search / 3 - search by last name): "; std::cin >> command;
    }
    
    --command;

    if(command == (int) add_to)
        add(phone_dir);
    else if (command == (int) ph_search)
        phone_search(phone_dir);
    else if (command == (int) searc_last_name)
        (ln_search(phone_dir)) ? (std::cout << "Search successful" << std::endl) 
                               : (std::cout << "Search don,t successful" << std::endl);
     
}