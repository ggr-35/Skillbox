#include <iostream>
#include "cpu.h"
#include "dick.h"
#include "gpu.h"
#include "kbd.h"

using std::cin, std::cout, std::endl;

int main()
{   
    cout << "Enter the data: (max 8 el)"
    kbd();
    cout << "Enter the command: ";
    std::string str;
    cin >> str;

    if (str == "cpu")
        compute();
    else if (str == "disk")
        disk();
    else if (str == "gpu")
        gpu();
    else
        std::cerr << "Error!";
}