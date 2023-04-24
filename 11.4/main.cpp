#include <iostream>

char get_item(std::string str_0, std::string str_1, std::string str_2, int x,
              int y) {
    if (y == 0)
        return str_0[x];
    if (y == 1)
        return str_1[x];
    if (y == 2)
        return str_2[x];
    else
        return 0;
}

std::string get_column(std::string str_0, std::string str_1, std::string str_2,
                       int i_col) {
    std::string column_str;
    for (int i = 0; i < 3; ++i) {
        for (int j = i_col; j < i_col + 1; ++j) {
            column_str += get_item(str_0, str_1, str_2, j, i);
        }
    }
    return column_str;
}

int main() {
    std::string str_0, str_1, str_2;
    std::cin >> str_0;
    std::cin >> str_1;
    std::cin >> str_2;
    int won_x = 0, won_o = 0, resul_x_count = 0, resul_o_count = 0;

    {
        std::string test_str;
        for (int i = 0; i < 3; ++i) {
            test_str += get_item(str_0, str_1, str_2, i, i);
        }
        if (test_str == "xxx") {
            ++won_x;
        } else if (test_str == "ooo") {
            ++won_o;
        }
    }

    std::string test_str;
    for (int i = 0; i < 3; ++i) {
        test_str += get_item(str_0, str_1, str_2, 2 - i, i);
    }
    if (test_str == "xxx") {
        ++won_x;
        resul_x_count += 3;
    } else if (test_str == "ooo") {
        ++won_o;
        resul_o_count += 3;
    }

    for (int r = 0; r < 2; ++r) {
        for (int i = 0; i < 3; ++i) {
            int x_count = 0, O_count = 0;
            for (int j = 0; j < 3; ++j) {

                if (get_item(str_0, str_1, str_2, j, i) == 'o') {
                    ++O_count;
                    ++resul_o_count;
                } else if (get_item(str_0, str_1, str_2, j, i) == 'x') {
                    ++x_count;
                    ++resul_x_count;
                } else if(get_item(str_0, str_1, str_2, j, i) != '.'){
                    std::cout << "Incorrect\n";
                    return 0;
                }
            }
            if (O_count == 3) {
                ++won_o;
            } else if (x_count == 3) {
                ++won_x;
            }
        }
        std::string col_0 = get_column(str_0, str_1, str_2, 0),
                col_1 = get_column(str_0, str_1, str_2, 1),
                col_2 = get_column(str_0, str_1, str_2, 2);
        str_0 = col_0;
        str_1 = col_1;
        str_2 = col_2;
    }

    if ((won_o != 0 && won_x != 0) ||
        (won_o > won_x && (resul_x_count > resul_o_count)) ||
        (won_x > won_o && (resul_o_count >= resul_x_count)) ||
        resul_o_count > resul_x_count)
        std::cout << "Incorrect\n";
    else if (won_o == won_x)
        std::cout << "Nobody\n";
    else if (won_o > won_x)
        std::cout << "Vanya won\n";
    else
        std::cout << "Petya won\n";
}