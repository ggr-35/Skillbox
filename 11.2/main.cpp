#include <iostream>

//Корректные адреса:
//simple@example.com
//very.common@example.com
//disposable.style.email.with+symbol@example.com
//other.email-with-hyphen@example.com
//fully-qualified-domain@example.com
//user.name+tag+sorting@example.com
//x@example.com
//example-indeed@strange-example.com
//admin@mailserver1
//example@s.example
//mailhost!username@example.org
//user%example.com@example.org

// Некорректные адреса:
//John..Doe@example.com
//Abc.example.com
//A@b@c@example.com
//a"b(c)d,e:f;g<h>i[j\k]l@example.com
//1234567890123456789012345678901234567890123456789012345678901234+x@example.com
//i_like_underscore@but_its_not_allow_in _this_part.example.com


std::string l_part_email(std::string str) {

    std::string left_str;
    for (int i = 0; str[i] != '@'; ++i) {
        left_str += str[i];
    }
    return left_str;
}

std::string r_part_email(std::string str) {

    std::string right_str;
    for (int i = l_part_email(str).length() + 1; i < str.length(); ++i) {
        right_str += str[i];
    }
    return right_str;
}

int main() {

    while (true) {
        std::cout << "Enter your email: " << std::endl;
        std::string str;
        std::getline(std::cin, str);

        int test = false;

        if (str[0] != '.' && str[str.length() - 1] != '.') {
            if (str.length() >= 3 && str.length() <= 128) {

                for (int i = 0; i < str.length(); ++i) {
                    if (str[i] == '@') {
                        test = true;
                        break;
                    }
                }

                for (int i = 0; i < str.length() - 1; ++i) {
                    if (str[i] == '.' && str[i + 1] == '.') {
                        test = false;
                        break;
                    }
                }

                if (test == false) {
                    std::cout << "\nError !\n";
                    continue;
                }

                std::string left = l_part_email(str);

                if (l_part_email(str).length() >= 1 && l_part_email(str).length() <= 64) {
                    std::string left_dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.!#$%&'*+-/=?^_`{|}~";
                    test = false;

                    for (int i = 0; i < left.length(); ++i) {

                        for (int j = 0; j < left_dictionary.length(); ++j) {

                            if (left[i] == left_dictionary[j]) {
                                test = true;
                                break;
                            } else
                                test = false;
                        }

                        if (test == false) {
                            break;
                        }
                    }


                    if (test == false) {
                        std::cout << "\nError ! Invalid characters\n";
                        continue;
                    }

                    test = false;

                    std::string right = r_part_email(str);
                    if (r_part_email(str).length() >= 1 && r_part_email(str).length() <= 63) {

                        std::string right_dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.";

                        for (int i = 0; i < right.length(); ++i) {

                            for (int j = 0; j < right_dictionary.length(); ++j) {

                                if (right[i] == right_dictionary[j]) {
                                    test = true;
                                    break;

                                } else
                                    test = false;
                            }
                            if (test == false) {
                                break;
                            }
                        }


                        if (test == false) {
                            std::cout << "\nError ! Invalid characters\n";
                            continue;
                        } else {
                             std::cout << "\nYes\n";
                        }

                    } else
                        std::cout << "Exceeding the number of characters on the right side\n";
                } else
                    std::cout << "Exceeding the number of characters on the left side\n";
            } else
                std::cout << "Size error\n";
        } else
            std::cout << "Address cannot start and end with a dot\n";
    }
}




