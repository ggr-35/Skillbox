#include <iostream>

using std::cout, std::cin, std::endl, std::string;

class Elf
{
private:
    string name = "unnnamed";

public:

    Elf()
    {
        cout << "Enter elfs name: ";
        cin >> name;
        cout << "Elf " << this->name << "was born." << endl;
    }
};



class Branch
{
private:
    int count = 0;
    Elf** elfs = nullptr;

public:

    int getCount()
    {
        return count;
    }

    Branch(int inCount) : count(inCount)
    {
        elfs = new Elf*[inCount];

        for (int i = 0; i < count; i++)
        {
            elfs[i] = new Elf();
        }
        
    }
};




int main()
{
    Branch* branch = new Branch(2);

}