#pragma once

#include <fstream>
using std::cin, std::cout, std::endl;
int data[8];

void compute()
{
    int sum = 0;

    for (int i = 0; i < 8; i++)
    {
        sum += data[i];
    }
    std::cout << sum << std::endl;
}





