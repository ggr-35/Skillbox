#include <iostream>

std::string get_address_part(std::string str, int index) {
    std::string result_str;

    int dot_count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '.') ++dot_count;
        if (index == dot_count && str[i] != '.') result_str += str[i];
    }
    return result_str;
}

bool check_address_part(std::string str){

    if (str.length() == 0 || str.length() > 3) return false;
    else {

        if (str.length() == 3 && str[0] == 0 || str.length() == 2 && str[0] == 0)
            return false;
        else {

            int result = 0;

            for (int i = 0; i < str.length(); ++i) {
                char buff = str[i] - '0';
                result = result * 10 + buff;
            }

            if (result < 0 || result > 255) return false;
            else {
                return true;
            }
        }
    }
}

int main() {

    while (true) {

        std::cout << "IP: " << std::endl;
        std::string str;
        std::cin >> str;
        bool test = true;
        for (int index = 0; index < 4; ++index) {
            if (check_address_part(get_address_part(str, index)) == false) {
                test = false;
                break;
            }
            std::cout << get_address_part(str, index) << " " << "decision = " << check_address_part(get_address_part(str, index)) << "\n";
        }
        (test) ? (std::cout << "Valid\n") : (std::cout << "Invalid\n");
        //egw4tgw4g4gw44g4w4w
    }
}