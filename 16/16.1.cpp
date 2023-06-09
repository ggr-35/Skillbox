#include <iostream>

int main() {

    double difference = 0;
    double speed = 0;
    char str[10];

    do {

        std::cout << "Enter your speed difference: \n";
        std::cin >> difference;
        speed+=difference;
        std::sprintf(str, "%.1f",speed);
        std::cout << str << std::endl;

    } while ((speed > 0) && (speed < 150));

}