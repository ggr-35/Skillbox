#include <iostream>
#include <sstream>

int main() {

    std::string buffer;

    while (true){

        std::cin >> buffer;
        std::stringstream buffer_stream(buffer);
        double x;
        double y;
        char action;
        buffer_stream >> x >> action >> y;

        if(action == '+'){
            std::cout << x + y << std::endl;
        } else if (action == '-')
        {
            std::cout << x - y << std::endl;
        } else if (action == '/')
        {
            std::cout << x / y << std::endl;
        } else if (action == '*')
        {
            std::cout << x * y << std::endl;
        } else 
            std::cout << "Invalid operation" << std::endl;
        
    }


}