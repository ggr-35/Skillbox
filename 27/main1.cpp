#include <iostream>

using std::cout, std::cin, std::endl, std::string;

class TrainCar
{

private:

    int passengersMax = 0;
    int passengers = 0;

public:

    void load(int value)
    {
        passengers += value;

        if(passengers > passengersMax)
            passengers = passengersMax;
    }

    int getPassengers()
    {
        return passengers;
    }

    TrainCar(int inPassengersMax): passengersMax(inPassengersMax)
    {
        assert(inPassengersMax >= 0);
    }

};

class Train
{
private:
    int count = 0;
    TrainCar** cars = nullptr;

public:

    TrainCar* gatCarAt(int index)
    {
        if (index < 0) return nullptr;
        if (index >= count) return nullptr;

        return cars[index];
    }

    int getCount()
    {
        return count;
    }

    // определяем конструктор класса, который автоматически выделяет массив типа - вагон 
    // в цикле добавляем по каждому указателю обьект "вагон"
    Train(int inCount, int inPassengersMax): count(inCount) // получем кол людей и макс кол / инициализируем количество 
    {
        cars = new TrainCar*[inCount]; // TrainCar** Создается динамический массив указателей на вагоны, называемый "cars", длиной inCount.

        for (int i = 0; i < count; i++)
        {
            cars[i] = new TrainCar(inPassengersMax); // Внутри цикла создается новый объект TrainCar со значением inPassengersMax, и указатель на этот объект присваивается текущему элементу массива cars.
        }
        
    }

};


int main()
{
   Train* train = new Train(10, 30); // динамически создаем обьект Train используя конструктор класса
    
   for (int i = 0; i < train->getCount(); i++) // инициализируем массив
   {
        int passengers = 0;
        cin >> passengers;
        train->gatCarAt(i)->load(passengers);
   }
   //TrainCar** cars = new TrainCar*[inCount];
}