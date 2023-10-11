#include <iostream>
int train [10] = {10, 20, 10, 30, 50, 40, 20, 20, 40, 20};
int count = 0;

#define FUNCTION_LOOOP(fun) for (int i = 0; i < 10; i++) { fun(i, train[i]); }

void check_full(int i, int train)
{
    if(train >= 20)
    {   
        std::cout << "Еhe car #" << i + 1 << " is full" << std::endl;
    }
    else
    {
        std::cout << "Еhe car #" << i + 1 << " isn't full" << std::endl;
    }     
}

void count_of(int i, int train)
{
    count+= train;
}


int main ()
{
   FUNCTION_LOOOP(check_full);
   FUNCTION_LOOOP(count_of);
   std::cout << count << std::endl;
}