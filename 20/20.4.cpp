#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void replenishment(int* vault,int& count)
{
    std::ofstream bank_file("/Users/german/Downloads/test.txt",std::ios::app | std::ios::binary);
    int banknotes[5] = {100, 500, 1000, 2000, 5000};

    for (int i = 0; i < 1000; i++)
    {
        *(vault + i) = banknotes[std::rand() % 4];
        bank_file << *(vault + i) << std::endl;
        count+= *(vault + i);
    }

    for (int i = 0; i < 1000; i++)
    {
        std::cout << vault[i] << std::endl;
    }
        std::cout << count;

    bank_file.close();
}

void withdrawal(int& count,int& desir_sum)
{
    count-= desir_sum;
}

int vault[1000], count = 0;

int main(){

    std::srand(std::time(nullptr));
    char user_oper;
    std::cout << "+/- ?  ";
    std::cin >> user_oper;

    if(user_oper == '+')
    {
        replenishment(vault, count);
    }
    else if(user_oper == '-' && count > 0)
    {   
        int desir_sum;
        std::cout << "How much money do you want to withdraw ?: ";
        std::cin >> desir_sum;

        if(desir_sum < count)
            withdrawal(count, desir_sum);
        else
             std::cerr << "Error of withdraw!" << std::endl;
        
    }
    else
        std::cerr << "Error of withdraw!" << std::endl;

}