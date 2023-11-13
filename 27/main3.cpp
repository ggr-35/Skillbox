#include <iostream>
#include <cstdlib>

using std::cout, std::cin, std::endl, std::string;

enum TipeOfWork {A, B, C};

class Worker
{
private:
    string name;
    bool busy;
    TipeOfWork tipe;
public:

    Worker(string name)
    {
        this->name = name;
        this->busy = false;
        this->tipe = A;
    }

    bool getStatus()
    {
        return busy;
    }

    void setStatus(bool status)
    {
        busy = status;
    }

    void setTipeOfWork()
    {
        tipe = static_cast<TipeOfWork>(rand() % 3);
        setStatus(true);
    }

    TipeOfWork getTipeOfWork()
    {
        return tipe;
    }

    string getName()
    {
        return name;
    }
};

class Manager
{
private:
    string name = "unnamed";
    int number = 0;
    Worker** workers = nullptr;
    int countOfWorkers = 0;
    int countOfFreeWorkers = countOfWorkers;
    bool loadingTheСommand = false;

public:

    Manager(string name, int number, int countOfWorkers)
    {
        this->name = name;
        this->number = number;
        this->countOfWorkers = countOfWorkers;
        this->countOfFreeWorkers = countOfWorkers;

        workers = new Worker*[countOfWorkers];

        for (int i = 0; i < countOfWorkers; i++)
        {
            string inName;
            cout << "Enter the name: ";
            cin >> inName;
            workers[i] = new Worker(inName);
        }
    }

    void distributeTasks(int command)
    {

        if(loadingTheСommand)
        {
            cout << "Command of manager " << name << "is full of work" << endl;
            return;
        }

        std::srand(command + number);
        command = rand() % countOfWorkers + 1;

     
        for (int i = 0; i < command; i++)
        {
            if (workers[i]->getStatus())
               continue;
            else
            {
                workers[i]->setTipeOfWork();

                --countOfFreeWorkers;
                if(countOfFreeWorkers == 0)
                {
                    loadingTheСommand = true;
                    break;
                }
            }
                
        }
        printStatus();
    }

    string getName()
    {
        return name;
    }

    void printStatus()
    {
        cout << "Team #" << number << " :" << endl;

        for (int i = 0; i < countOfWorkers; i++)
        {
             cout << "* " << workers[i]->getName() << " ";

            if(workers[i]->getStatus()) 
                cout << workers[i]->getTipeOfWork();
            else 
                cout << "chill...";
            
            cout << endl << endl;
        }
    }

    int getloadingTheСommand()
    {
        return loadingTheСommand;
    }


};

class Chief
{
private:
    string name = "unnamed";
    int countOfManagers = 0;
    Manager** manager = nullptr;

public:

    Chief(string name, int countOfManagers)
    {
        this->name = name;
        this->countOfManagers = countOfManagers;
        manager = new Manager*[countOfManagers];

        for (int i = 0; i < countOfManagers; i++)
        {

           cout << "Enter the count of workers in team №" << i << ": ";
           int countOfWorkers = 0;
           cin >> countOfWorkers;
           manager[i] = new Manager("Manager#" + i, i, countOfWorkers);
        }
    }

    void giveAssignment()
    {
        
        cout << "Enter the command: ";
        int command = 0;
        cin >> command;

        for (int i = 0; i < countOfManagers; i++)
        {
            manager[i]->distributeTasks(command);
        }
        
    }

    bool loadingTheManager()
    {
        for (int i = 0; i < countOfManagers; i++)
        {
            if (!manager[i]->getloadingTheСommand())
                return false;
        }
        return true;
    }
};




int main()
{
    Chief chief("German", 3);

    
    while (!chief.loadingTheManager())
    {
        chief.giveAssignment();
    }
    

}