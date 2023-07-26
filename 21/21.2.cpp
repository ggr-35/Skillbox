#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::endl;



/*
    
     plots(number)
        buildings(tipe,s)
            house (s, floors, rooms, tipe of room, pipe)
            garage (s)
            shed (s)
            sauna (s, pipe)
    */


enum room_tipes
{
    bedroom,
    kitchen,
    bathroom,
    children_room,
    living_room,
};

enum bilding_types
{   
    house,
    garage,
    shed,
    sauna,
};

struct rooms
{   
    int room_number;
    double sq;
    int tipe;
};

struct floors
{   
    int floor_number;
    int room_on_floor;
    double h;
    std::vector<rooms> room;
};

struct houses
{   
    bool availabil;
    int floor_count;
    bool pipe;
    std::vector<floors> floor;
};

struct plots
{
   int plots_number;
   houses hous;
};

struct township
{
    int plot_count;
    std::vector<plots> plot;
};
 
township new_town;
houses new_house;

void input_house()
{
            cout << "How many floors are there in your house ? ";
            cin >> new_house.floor_count;
            new_house.floor.resize(new_house.floor_count);

            for (int i = 0; i < new_house.floor_count; i++)
            {   
                new_house.floor[i].floor_number = i + 1;

                cout << "What is the ceiling height on the floor " << i + 1 << ": ";
                cin >> new_house.floor[i].h;

                cout << "How many rooms are there on floor " << i + 1 << ": ";
                cin >> new_house.floor[i].room_on_floor;
                new_house.floor[i].room.resize(new_house.floor[i].room_on_floor);

                        for (int j = 0; j < new_house.floor[i].room_on_floor; j++)
                        {   
                            new_house.floor[i].room[j].room_number = j + 1;
                            cout << "Room №" << j + 1 << endl;
                            cout << "Square of room: " ;
                            cin >> new_house.floor[i].room[j].sq;
                            cout << "Tipe of room: " ;
                            cin >> new_house.floor[i].room[j].tipe;
                        }
            }
}

void output_house()
{
    cout << "House " << endl;
    cout << "Floors count: " << new_house.floor_count << endl;

    for (int i = 0; i < new_house.floor_count; i++)
    {
       cout << "flor №" << new_house.floor[i].floor_number << endl;
       cout << "  h of floor: " << new_house.floor[i].h << endl;
       cout << "  room count: " << new_house.floor[i].room_on_floor << endl;

       for (int j = 0; j < new_house.floor[i].room_on_floor; j++)
       {
            cout << "room №" << new_house.floor[i].room[j].room_number << endl;
            cout << "   Square of room: " << new_house.floor[i].room[j].sq << endl;
            cout << "   Tipe of room: " << new_house.floor[i].room[j].tipe << endl;
       }
    }
}



int main()
{   
   
    cout << "How many plots in your township ? ";
    cin >> new_town.plot_count;
    new_town.plot.resize(new_town.plot_count);

        for (int i = 0; i < new_town.plot_count; i++)
        {
            new_town.plot[i].plots_number = i + 1;
            cout << "Do you have a house in your plots №" << new_town.plot[i].plots_number << " (1 - YES/ 0 - NO)" << endl;
            cin >> new_town.plot[i].hous.availabil;

            if(new_town.plot[i].hous.availabil)
            {
                input_house();
                output_house();
            }
                
        }   

        

    
    
    
    
   
   
   
   
   
   
   
   
   
   
   
   
   
    

                    
                  
                    
                    
                    
                    
                    





}