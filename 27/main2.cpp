#include <iostream>
#include <math.h>
using std::cout, std::cin, std::endl, std::string;


class geomShape
{
private:
    double centre = 0;
    enum colour {red, blue, green};

public:
   
};

class circle : public geomShape
{
private:
    double radius = 0;
public:

    double square()
    {
       return atan(1) * 4 * radius;
    }

    void describing_rectangle()
    {
        cout << "a = " << this->radius << endl;
        cout << "b = " << this->radius << endl;
    }

};

class triangle : public geomShape
{
private:
    double length = 0;
    
public:

    double square()
    {
       return length * length * std::sqrt(3) / 4;
    }

    void describing_rectangle()
    {
        cout << "a = " << length * std::sqrt(3) / 2 << endl;
        cout << "b = " << length << endl;
    }

};

class square : public geomShape
{
private:
    double length = 0;
    
public:

    double square()
    {
       return length * length;
    }

    void describing_rectangle()
    {
        cout << "a = " << length << endl;
        cout << "b = " << length << endl;
    }

};

class rectangle : public geomShape
{
private:
    double a = 0;
    double b = 0;

public:

    double square()
    {
       return a * b;
    }

    void describing_rectangle()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }

};




int main()
{
    
}