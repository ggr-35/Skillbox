#include <iostream>

void evendigits(long long num, int& even_num){

    if(((num % 10) % 2) == 0)
        ++even_num;

    if(num / 10 != 0){
        num /= 10;
        evendigits(num, even_num);
    }

}


int main() {

int ans = 0;

evendigits(9223372036854775806, ans);

std::cout << ans << std::endl;

}