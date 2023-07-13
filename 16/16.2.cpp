#include <iostream>

int main() {
    std::cout << "Enter the whole and fractional parts separated by a space: ";
    std::string integer_p;
    std::string fractional_p;
    std::cin >> integer_p >> fractional_p;
    std::string str = integer_p + '.' + fractional_p;
    double x = std::stod(str);
    std::cout << x;
}