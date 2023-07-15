#include <iostream>
#include <fstream>
#include <vector>

void game_start(bool field[])
{
     for (int i = 0; i < 13; i++)
    {
       field[i] = false;
    }
    
}

std::string get(std::string file_address, int sector)
{
    std::ifstream user_file;
    user_file.open(file_address);

    if(!user_file.is_open())
    {
        std::cerr << "File open error!\n";
        exit(1);
    }

    std::string buff;

    for (int i = 0; i <= sector || user_file.eof(); i++)
    {
       user_file >> buff;
    }
    
    return buff;
}


int main(){
    
    std::string a_file_name = "/Users/german/Library/Mobile Documents/com~apple~TextEdit/Documents/answers.txt",
                q_file_name = "/Users/german/Downloads/questions.txt", 
                user_answer;

    bool game_field[13];
    game_start(game_field);

    int sector = 0,
        offset,
        player_1 = 0,
        player_2 = 0,
        turn = 1;


    while (player_1 < 6 && player_1 < 6)
    {
       std::cout << "player_1: " << player_1 << " " << "player_2: " << player_2 << std::endl;
       std::cout << "Sector: " << sector + 1 << " Enter the offset: ";
       std::cin >> offset;
       
       ((sector + offset) > 13) ? (sector += offset % 13) : (sector += offset);

       if(game_field[sector])
       {    
            while (game_field[sector])
            {  
               ((sector + 1) > 13) ? (sector += 1 % 13) : (sector += 1);

            }
            std::cout << "This sector has already been selected" << std::endl;
            std::cout << "New Sector is: " << sector + 1 << std::endl;
       }

        std::cout << get(q_file_name, sector) << " Your answer is: ";
        std::cin >> user_answer;

        if(get(a_file_name, sector) == user_answer)
        {
            game_field[sector] = true;
            (turn == 1) ? (++player_1) : (++player_2);
        }

        for (int i = 0; i < 13; i++)
        {
            std::cout << game_field[i];
        }
        
        (turn == 1) ? (turn = 2) : (turn = 1);
    }

    (player_1 > player_2) ? (std::cout << player_1 << " won!" << std::endl) 
                          : (std::cout << player_2 << " won!" << std::endl);

}