#include <iostream>

#define MONDAY "MONDAY"
#define TUESDAY "TUESDAY"
#define WEDNSDAY "WEDNSDAY"
#define THURSDAY "WEDNSDAY"
#define FRIDAY "WEDNSDAY"
#define SATURDAY "WEDNSDAY"
#define SUNDAY "WEDNSDAY"

#define DAY_OF_WEEK(WEEK) WEEK ## DAY

int main()
{
    int number = 0;
    std::cin >> number;

    if(number == 1)
        std::cout << DAY_OF_WEEK(MON);
    else if (number == 2)
    {
        std::cout << DAY_OF_WEEK(TUES);
    }
    else if (number == 3)
    {
        std::cout << DAY_OF_WEEK(WEDNS);
    }
    else if (number == 4)
    {
        std::cout << DAY_OF_WEEK(THURS);
    }
    else if (number == 5)
    {
        std::cout << DAY_OF_WEEK(FRI);
    }
    else if (number == 6)
    {
        std::cout << DAY_OF_WEEK(SATUR);
    }
    else if (number == 7)
    {
        std::cout << DAY_OF_WEEK(SUN);
    }
    else
        std::cerr << "Error !" << std::endl;
}