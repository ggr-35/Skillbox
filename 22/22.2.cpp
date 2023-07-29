#include <iostream>
#include <map>
using std::string, std::cin, std::cout, std::endl;

int main()
{
    std::map<string, int>registry;
    
    while (true)
    {   
        string client;
        cout << "Enter: "; cin >> client;

        if(client == "Next" && !registry.empty())
        {
            cout << "The queue is empty!" << endl;
            continue;
        }
           
        if(client == "Next")
        {   
            cout << registry.begin()->first << endl;

            if(registry.begin()->second - 1 == 0)
                registry.erase(registry.begin());
            else
                --registry.begin()->second;

        }
        else
        {    
                
            if(registry.count(client) == 0)
                registry.insert(std::make_pair<string, int>(client, 1));
            else
                ++registry.find(client)->second;
        }
        
        for (std::map<string, int>::iterator it = registry.begin(); it != registry.end(); it++)
            cout << it->first << " " << it->second << endl;
    }        
}