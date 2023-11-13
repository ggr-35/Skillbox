#include <iostream>

using std::cout, std::cin, std::endl, std::string;

class Elf
{
private:
    string name = "unnamed";
public:

    Elf()
    {
        cout << "Enter the elf name: ";
        cin >> name;
    }

    string getname()
    {
        return name;
    }
};

class ElfHouse
{
private:
    int countOfElfs = 0;
    Elf** elfs = nullptr;
public:
   
   ElfHouse(int countOfElfs)
   {
        this->countOfElfs = countOfElfs;
        elfs = new Elf*[countOfElfs];

        for (int i = 0; i < countOfElfs; i++)
        {
            elfs[i] = new Elf;
        }
   }

   int getCount()
   {   
        return countOfElfs;
   }

   Elf** getElfs()
   {
        return elfs;
   }

};

class Branch
{
private:
    int countOfElfsHouse = 0;
    ElfHouse** elfHouse = nullptr;
public:
  
    Branch(int countOfElfsHouse)
    {
        this->countOfElfsHouse = countOfElfsHouse;
        elfHouse = new ElfHouse*[countOfElfsHouse];

        for (int i = 0; i < countOfElfsHouse; i++)
        {
            elfHouse[i] = new ElfHouse(1);
        }
        
    }
    
};


int main()
{
    
}