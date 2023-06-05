#include <iostream>
#include <math.h>

void input_ship(bool field[][10],int size_of_ship){

        std::cout << "Enter the coordinate of the ship (size: " << size_of_ship <<")\n";

        std::cout << "X1: ";
        int x1;
        std::cin >> x1;
        std::cout << "Y1: ";
        int y1;
        std::cin >> y1;
        std::cout << "X2: ";
        int x2;
        std::cin >> x2;
        std::cout << "Y2: ";
        int y2;
        std::cin >> y2;

       while (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || 
            x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9 || 
            field[x1][y1] || field[x2][y2] 
            ||((((fabs(y1 - y2)) + 1) != size_of_ship)
             && (((fabs(x1 - x2)) + 1) != size_of_ship)) 
            ||((x1 != x2) && (y1 != y2)))
            {
        
                if(x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9)
                    std::cout << "Invalid coordinate\n";
                else if (field[x1][y1] || field[x2][y2] )
                    std::cout << "Еhere is already a ship at this coordinate\n";
                else if ((((fabs(y1 - y2)) + 1) != size_of_ship) && (((fabs(x1 - x2)) + 1) != size_of_ship))
                    std::cout << "Exceeding the size of the ship\n";
                else
                    std::cout << "The ship cannot be positioned diagonally\n";

                std::cout << "X1: ";
                std::cin >> x1;
                std::cout << "Y1: ";
                std::cin >> y1;
                std::cout << "X2: ";
                std::cin >> x2;
                std::cout << "Y2: ";
                std::cin >> y2;
    }

                if((x1 >= x2) && (y1 >= y2)){
                    int buf_1 = x1;
                    int buf_2 = y1;
                    x1 = x2;
                    y1 = y2;
                    x2 = buf_1;
                    y2 = buf_2;
                }

                for (int i = x1; i <= x2; i++){
                    for (int j = y1; j <= y2; j++){
                        field[i][j] = true;
                    }
                }
}
    

void input_one_ship(bool field[][10]){

        std::cout << "Enter the coordinate of the ship (size: 1)\n";
        std::cout << "X: ";
        int x;
        std::cin >> x;
        std::cout << "Y: ";
        int y;
        std::cin >> y;

        while (x < 0 || x > 9 || y < 0 || y > 9 || field[x][y]){

             (x < 0 || x > 9 || y < 0 || y > 9) ? (std::cout << "Invalid coordinate\n") : (std::cout << "Еhere is already a ship at this coordinate\n");
             std::cout << "X: ";
             std::cin >> x;
             std::cout << "Y: ";
             std::cin >> y;
        }

     field[x][y] = true;
}

void print_field(bool field[][10],int player){
    std::cout << "Player number " << player << " turn\n";
    std::cout << std::endl;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

void input_field(bool field[][10]){
    for (int i = 0; i < 10; i++)
    {
       for (int j = 0; j < 10; j++)
       {
        field[i][j] = false;
       }
    }
    
}

void shot(bool field[][10],int player){

    std::cout << "Player number " << player << " turn\n";
    std::cout << std::endl;
    std::cout << "Enter the coordinates of the shot\n";
    std::cout << std::endl;
    std::cout << "X: ";
    int x;
    std::cin >> x;
    std::cout << "Y: ";
    int y;
    std::cin >> y;

    while (x < 0 || x > 9 || y < 0 || y > 9){
    std::cout << "Invalid coordinate\n";
    std::cout << std::endl;
    std::cout << "X: ";
    int x;
    std::cin >> x;
    std::cout << "Y: ";
    int y;
    std::cin >> y;
    }

    if(field[x][y]){
        field[x][y] = false;
        std::cout << "Hit!\n";
    }else
        std::cout << "Missed!\n";
    
     std::cout << std::endl;
}

bool stop_the_game(bool field[][10]){
    for (int i = 0; i < 10; i++){
       for (int j = 0; j < 10; j++){
        if (field[i][j])
        {
        return false;
        }
       }
    }
    return true;
}



int main(){

    bool field_1 [10][10];
    bool field_2 [10][10];
    input_field(field_1);
    input_field(field_2);

    print_field(field_1,1);
    input_one_ship(field_1);
    print_field(field_2,2);
    input_one_ship(field_2);

for (int size = 2; size < 5; ++size){
        print_field(field_1,1);
        input_ship(field_1,size);
        print_field(field_2,2);
        input_ship(field_2,size);
}


    while (!stop_the_game(field_1) && !stop_the_game(field_2))
    {
        shot(field_2,1);
        shot(field_1,2);
    }
    
    (stop_the_game(field_1)) ? (std::cout << "Player 2 won !") : (std::cout << "Player 1 won !");

    std::cout << std::endl;
}
