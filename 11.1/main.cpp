#include <iostream>
using std::cout,std::cin;

std::string encrypt_caesar(std::string str, int offset){

    std::string encrypt_str;

    for(int i = 0; i < str.length(); ++i){

        char a,z;

        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
            (str[i] >= 'A' && str[i] <= 'Z') ? (a = 'A', z = 'Z') : (a = 'a', z = 'z');
            (str[i] - a + offset < 0) ? (str[i] = z + (str[i] - a + offset) + 1 ) : (str[i] = (str[i] - a + offset) % 26 + a) ;

        }
        encrypt_str += str[i];
    }
    return encrypt_str;
}

std::string decrypt_caesar(std::string str, int offset){
    offset *= -1;
    encrypt_caesar(str,offset);
    return str;
}

int main() {

        cout << "Enter the text: ";
        std::string str;
        std::getline(cin, str);
        cout << "Enter the offset: ";
        int offset;
        cin >> offset;
        cout << encrypt_caesar(str,offset);

        cout << "\nDo you want to decrypt ? ";
        std::string answer;
        cin >> answer;

        if (answer == "Yes")
            cout << decrypt_caesar(str, offset);

    }
