#include <iostream>
#include <sstream>

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main()
{
    int melody[12];

    for (int i = 0; i < 12; ++i)
    {
        std::string notes = "";
        std::cout << "Notes:";//123
        std::cin >> notes; 
        melody[i] = 0; 
        for (int j = 0; j < notes.length(); ++j)
        {
            std::string letter = std::string(1, notes[j]);// 1 2
            int index = std::stoi(letter) - 1; // 2 - 1 = 1
            melody[i] |= 1 << index; //
            //1 10 100
        }
    }

    std::cout << "Melody:" << std::endl;
    for (int i = 0; i < 12; ++i)
    {
        int notes = melody[i];
        std::stringstream buffer;
        if (notes & DO)
        {
            buffer << "DO ";
        }
        if (notes & RE)
        {
            buffer << "RE ";
        }
        if (notes & MI)
        {
            buffer << "MI ";
        }
        if (notes & FA)
        {
            buffer << "FA ";
        }
        if (notes & SOL)
        {
            buffer << "SOL ";
        }
        if (notes & LA)
        {
            buffer << "LA ";
        }
        if (notes & SI)
        {
            buffer << "SI ";
        }
        std::cout << buffer.str() << std::endl;
    }

    return 0;
}













/*
enum note 
{ 
    DO = 1,     //      01
    RE = 2,     //      10
    MI = 4,     //     100
    FA = 8,     //    1000
    SOL = 16,   //   10000
    LA = 32,    //  100000
    SI = 64     // 1000000
};

int main() {

std::string buffer;
std::getline(std::cin, buffer);
std::stringstream buffer_stream(buffer);


int x[3], melody = 0;

    for (int i = 0; i < 3; i++)
    {

        std::cin >> x[i];
        melody |= x[i];
    }
        
        if (melody & DO) 
            { 
                std::cout << "DO "; 
            }
        if (melody & RE) 
            { 
                std::cout << "RE "; 
            }
        if (melody & MI) 
            { 
                std::cout << "MI "; 
            }
        if (melody & FA) 
            { 
                std::cout << "FA "; 
            }
        if (melody & SOL) 
            { 
                std::cout << "SOL "; 
            }
        if (melody & LA) 
            { 
                std::cout << "LA "; 
            }
        if (melody & SI) 
            { 
                std::cout << "SI "; 
            }else
                std::cerr << "Error\n";



*/

