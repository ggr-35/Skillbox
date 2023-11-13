#include <iostream>
#include "f.h"
using std::cout, std::cin, std::endl;


int main()
{
    cout << "Operation started!" << endl;
    cout << "Enter x1, y1, x2, y2 for scalpel: ";
    section newsection, startsection;
    std::string comm;
    cin >> startsection.pone.x >> startsection.pone.y >> startsection.ptwo.x >> startsection.ptwo.y;
    newsection.scalpel(newsection);

    while (true)
    {
        cout << "Enter the command: ";
        cin >> comm;
        cout << "Enter x1, y1, x2, y2 for scalpel: ";
        cin >> newsection.pone.x >> newsection.pone.y >> newsection.ptwo.x >> newsection.ptwo.y;
        
        if (comm == "hemostat")
            newsection.hemostat(newsection);
        else if (comm == "tweezers")
            newsection.tweezers(newsection);
        else if (comm == "suture")
            newsection.suture(newsection, startsection);
        else
            std::cerr << "Error";
    }
    
}