#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


int main(){

    std::srand(std::time(nullptr));
    int width, height;
    std::cout << "Width, Height: ";
    std::cin >> width >> height;
    std::ofstream file_pic("/Users/german/Library/Mobile Documents/com~apple~TextEdit/Documents/answers.txt");
    int pic [width][height];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
           pic[i][j] = std::rand() % 2;
           file_pic << pic[i][j] << " ";
        }
          file_pic << std::endl;
    }   
    file_pic.close();
}