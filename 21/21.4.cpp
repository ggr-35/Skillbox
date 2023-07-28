#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin, std::cout, std::vector, std::endl, std::string; 



enum character_type
{
    player,
    enemy,
};

struct position
{
  int x;
  int y;
};

struct character
{   
    character_type type;
    string Name = "unnamed";
    position pos;
    int Life = 0;
    int Armor = 0;
    int Damage = 0;
}new_ch;


void back_map(char map[][20])
{
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 19; j++)
        {   
            map[i][j] = '.';
        }
    }
}

void print_map(char map[][20])
{
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 19; j++)
        {   
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void draw_map(char map[][20], bool pos[][20], vector<character>& characters)
{
    back_map(map);

    for (int k = 0; k < characters.size(); k++)
    {
        for (int i = 0; i <= 19; i++)
        {
            for (int j = 0; j <= 19; j++)
            {   
                if(i == characters[k].pos.x && j == characters[k].pos.y)
                   (characters[k].type == player) ? (map[i][j] = 'P') : (map[i][j] = 'E');
            }   
        }
    }
    print_map(map);
}

void end_of_game(vector<character>& characters)
{   
    if(characters.size() == 1 && characters[0].Life > 0)
    {
        cout << "You won !";           
        exit(EXIT_SUCCESS);
    }
    else if (characters[0].Life <= 0)
    {
        cout << "You lose !";
        exit(EXIT_SUCCESS);
    }
}

bool damage(vector<character>& characters, bool pos[][20], int x , int y, int j)
{   
   for (int i = 0; i < characters.size(); i++)
   {
        if(characters[i].pos.x == x && characters[i].pos.y == y 
        && characters[i].type != characters[j].type)
        {
            if((characters[i].Life - characters[j].Damage) > 0)
            {   
                characters[i].Life-= characters[j].Damage;
                cout << characters[i].Name << " Damage: " << characters[j].Damage << " Life: " << characters[i].Life << endl;
                end_of_game(characters);
                return true;
            }
            else
            {
                cout << characters[i].Name << " dead! " << endl;
                if(characters[i].type == enemy)
                {
                     characters.erase(characters.begin() + i);
                     end_of_game(characters);
                     return false;
                }
                else
                {
                    cout << "You lose !";
                    exit(EXIT_SUCCESS);
                }
            }
        }
   }
   return false;
}

void move(char map[][20], bool pos[][20], vector<character>& characters)
{
    char comm_list [4] = {'a', 's', 'w', 'd'};

    for (int i = 0; i < characters.size(); i++)
    {
        string command;

        if(characters[i].type == player)
        {   
            cout << "Enter the comand(a,s,w,d): ";
            cin >> command;
        }
        else
        {
            command = comm_list[rand() % 4];
        }

            if(command == "w" && characters[i].pos.x > 0 && !damage(characters, pos, characters[i].pos.x - 1, characters[i].pos.y, i))
            {
                pos[characters[i].pos.x][characters[i].pos.y] = false;
                --characters[i].pos.x;
                pos[characters[i].pos.x][characters[i].pos.y] = true;
            }
            else if(command == "s" && characters[i].pos.x < 19 && !damage(characters, pos, characters[i].pos.x + 1, characters[i].pos.y, i))
            {
                pos[characters[i].pos.x][characters[i].pos.y] = false;
                ++characters[i].pos.x;
                pos[characters[i].pos.x][characters[i].pos.y] = true;
            }
            else if(command == "a" && characters[i].pos.y > 0 && !damage(characters, pos, characters[i].pos.x, characters[i].pos.y - 1, i))
            {
                pos[characters[i].pos.x][characters[i].pos.y] = false;
                --characters[i].pos.y;
                pos[characters[i].pos.x][characters[i].pos.y] = true;
            }
            else if(command == "d" && characters[i].pos.y < 19 && !damage(characters, pos, characters[i].pos.x, characters[i].pos.y + 1, i))
            {
                pos[characters[i].pos.x][characters[i].pos.y] = false;
                ++characters[i].pos.y;
                pos[characters[i].pos.x][characters[i].pos.y] = true;
            }
    }
}

int main()
{  

    std::srand(std::time(nullptr));
    vector<character> characters;
    char map[20][20];
    back_map(map);
    bool pos[20][20] = {false};

    new_ch.type = player;
    cout << "Enter the name: "; cin >> new_ch.Name;
    cout << "Enter the life's: "; cin >> new_ch.Life;
    cout << "Enter the armor: "; cin >> new_ch.Armor;
    cout << "Enter the damage: "; cin >> new_ch.Damage;
    new_ch.pos.x = rand() % 19;
    new_ch.pos.y = rand() % 19;
    pos[new_ch.pos.x][new_ch.pos.y] = true;
    characters.push_back(new_ch);

    

    for (int i = 0; i < 5; i++)
    {   
        new_ch.type = enemy;
        new_ch.Name = "Enemy #" + std::to_string(i + 1);
        new_ch.Life = rand() % 150 + 50;
        new_ch.Armor = rand() % 50;
        new_ch.Damage = rand() % 30 + 15;
        new_ch.pos.x = rand() % 19;
        new_ch.pos.y = rand() % 19;

        while (pos[new_ch.pos.x][new_ch.pos.y])
        {
            new_ch.pos.x = rand() % 19;
            new_ch.pos.y = rand() % 19;
        }
        pos[new_ch.pos.x][new_ch.pos.y] = true;
        characters.push_back(new_ch);
    }

    while (true)
    {
        draw_map(map, pos, characters);
        move(map, pos, characters);
    }
}