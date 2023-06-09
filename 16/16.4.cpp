#include <iostream>
#include <sstream>

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

   std::string str;
   int melody[3];
   std::cin >> str;

   for (int i = 0; i < 3; i++)
   {
    melody[i] = str[i];
    int notes = 1 << ( melody[i] - 1);
   
   if(notes & DO){
    std::cout << "DO" << " ";
   }
   if(notes & RE){
    std::cout << "RE" << " ";
   }
   if(notes & MI){
    std::cout << "MI" << " ";
   }
   if(notes & FA){
    std::cout << "FA" << " ";
   }
   if(notes & SOL){
    std::cout << "SOL" << " ";
   }
   if(notes & LA){
    std::cout << "LA" << " ";
   }
   if(notes & SI){
    std::cout << "SI" << " ";
   }else
    std::cout << "Erro\n";

   }
}