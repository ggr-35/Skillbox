#include <iostream>
#include <fstream>
#include <vector>


int main(){   
    std::ifstream user_file;
    user_file.open("/Users/german/Downloads/bank.txt");

    std::string f_name, l_name, data, winer;
    int money, sum = 0, max = 0;

    
    while (!user_file.eof())
    {
        money = 0;
        user_file >> f_name >> l_name >> money >> data;

        if(money > max){
            max = money;
            winer = f_name + " " + l_name;
        }
        sum+= money;
        
    }
    
    
    std::cout << "Total: " << sum << " Max: " << winer << " " << max << std::endl;

    /*for (int i = 0; i < sum.size(); i++)
    {
        std::cout << sum[i];
    }*/
    
    
    
    
    
    




}