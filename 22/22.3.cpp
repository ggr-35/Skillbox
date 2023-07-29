#include <iostream>
#include <map>
#include <string>
using std::string, std::cin, std::cout, std::endl, std::map;


bool anagram(string str_1, string str_2)
{   
    string str = str_1 + str_2;
    const char *chars = str.c_str();
    map<char, int> word;

    for (size_t i = 0; i < str.length(); i++)
    {
        if(word.count(*(chars + i)) == 0)
            word.insert(std::make_pair<char, int>(*(chars + i), 1));
        else
            ++word.find(*(chars + i))->second;
    }

    if(word.size() == str_1.length())
        return true;
    else
        return false;
}

int main()
{   
    string str_1 = "Boris", str_2 = "siroB";
    (anagram(str_1, str_2)) ? (cout << "Words are anagrams") : (cout << "Words are n't anagrams");
    cout << endl;
}