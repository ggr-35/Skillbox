/*
Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение. 
Воспроизведение симулируется с помощью вывода в консоль всей информации о записи. Если произведение какой-то записи уже начато, ничего не происходит.

Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль. Если запись уже на паузе или не воспроизводится вовсе, ничего не происходит.
Команда next переходит к следующей записи для воспроизведения. Запись при этом выбирается случайно, как будто плеер работает в режиме shuffle.
Команда stop прекращает воспроизведение текущей записи, если таковая имеется. Об этом выводится сообщение в консоль. Два раза остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.
Команда exit — выход из программы.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cstdlib>

using std::string, std::cout, std::cin, std::endl, std::time_t, std::vector;

class Track
{
    friend class Player;

    std::time_t now = std::time(nullptr);
    std::tm* trackdata = std::localtime(&now);
    std::tm* trackduration = std::localtime(&now);
    string trackname = "unnamed";
    bool playback = false;
    
    bool setptruelayback()
    {
        return playback = true;
    }

    bool setpfalselayback()
    {
        return playback = false;
    }

    void settrack()
    {
        cout << "Enter name: ";
        cin >> trackname;
        cout << "Data(D/M/Y): ";
        cin >> std::get_time(trackdata,"%d/%m/%y");
        cout << "Time(M:S): ";
        cin >> std::get_time(trackduration,"%M:%S");
        cout << endl;
    }

    void gettrack()
    {
        cout << "Name: " << trackname << " Data: " << std::put_time(trackdata,"%y/%m/%d") 
            << " Time: " << std::put_time(trackduration,"%M:%S") <<  endl;
    }

    string getname()
    {
        return trackname;
    }

    bool getplayback()
    {
        return playback;
    }
};

class Player
{
private:
    vector<Track> data;

    bool playcheck()
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].getplayback())
                return true;
        }
        return false;
    }

public:
    
    void setplayer()
    {
        cout << "Enter the count of tracks: ";
        int datasize;
        cin >> datasize;
        data.resize(datasize);

        for (int i = 0; i < data.size(); i++)
        {
          data[i].settrack();
        }
    }

    void showplayer()
    {
        for (int i = 0; i < data.size(); i++)
        {
          data[i].gettrack();
        }
    }

    void play()
    {
        if(!playcheck())
        {
            cout << "Enter the search track: ";
            string searchtrack;
            cin >> searchtrack;
            
            for (int i = 0; i < data.size(); i++)
            {
                if(searchtrack == data[i].getname())
                {
                    data[i].setptruelayback();
                    data[i].gettrack();
                    break;
                }
            }
        }
        else
            cout << "The track is already playing!" << endl;
    }

    void stop()
    {
        if(playcheck())
        {

            for (int i = 0; i < data.size(); i++)
            {
                if(data[i].getplayback())
                    data[i].setpfalselayback();
            }
               cout << "Track stopped!" << endl;
        }
        else
            cout << "The track is already stopped!" << endl;
    }

    void next()
    {  
        if(playcheck())
        {
            int currentlyplaying;
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i].getplayback())
                    currentlyplaying = i;
            }
            
            stop();

            int rand_i = rand() % data.size();

            while (rand_i == currentlyplaying)
                rand_i = rand() % data.size();

            data[rand_i].gettrack();
            data[rand_i].setptruelayback();

        }
        else
            cout << "No track is being played!" << endl;
    }

    void pause()
    {
        cout << "Track Is Paused\n"<< endl;
        std::system("pause");
    }

};

int main()
{
    Player player;
    player.setplayer();
    player.showplayer();

    int command;

    while (true)
    {   
        cout << "Enter the command: ";
        cin >> command;
        if (command == 1) player.play();
        else if (command == 2) player.stop();
        else if (command == 3) player.next();
        else if (command == 4) player.pause();
        else if (command == 5) exit(EXIT_SUCCESS);
        else cout << "Error!" << endl;
    }
}