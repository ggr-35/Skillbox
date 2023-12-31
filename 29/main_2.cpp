#include <iostream>
#include <cmath>
#include <vector>

using std::cout, std::cin, std::endl;

struct BoundingBoxDimensions
{
    double a;
    double b;
};

class Shape
{
public:

    virtual double square() = 0;

    virtual BoundingBoxDimensions dimensions() = 0;

    virtual std::string type() = 0;

    virtual ~Shape(){}
};

class Triangle : public Shape
{
    double sideA;
    double sideB;
    double sideC;
    double p;
public:

    Triangle(int a, int b, int c)
    {
        sideA = a;
        sideB = b;
        sideC = c;
        p = (sideA + sideB + sideC) / 2;
    }

    double square()
    {
        return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }

    BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions BBD;
        BBD.a = sideA * sideB * sideC / (4 * std::sqrt(p*(p - sideA)*(p - sideB)*(p - sideC))) * 2;
        BBD.b = BBD.a;
        return BBD;
    }
    
    std::string type()
    {
        return "Triangle";
    }
};

class Circle : public Shape
{
private:
    double r;
public:
    Circle(double r)
    {
        this->r = r;
    }

    double square()
    {
        return 2 * M_PI * r;
    }

    BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions BBD;
        BBD.a = r * 2;
        BBD.b = r * 2;
        return BBD;
    }
    
    std::string type()
    {
        return "Circle";
    }
};

void printParams(Shape *shape)
{
    cout <<"Type: " << shape->type() << std::endl;
    cout <<"Squer: " << shape->square() << std::endl;
    cout <<"Wihgt: " << shape->dimensions().a << std::endl;
    cout <<"Height: " << shape->dimensions().b << std::endl;
    cout << endl;
}

class Rectangle : public Shape
{
double a;
double b;

public:

    Rectangle(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    double square()
    {
        return a * b;
    }

    BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions BBD;
        BBD.a = a;
        BBD.b = b;
        return BBD;
    }
    
    std::string type()
    {
        return "Rectangle";
    }


};



int main()
{   
    Shape* shapes[4];
    shapes[0] = new Triangle(2,3,4);
    shapes[1] = new Circle(8);
    shapes[2] = new Rectangle(2,2);
    shapes[3] = new Circle(4);

    for (int i = 0; i < 4; i++)
        printParams(shapes[i]);
    
    for (int i = 0; i < 4; i++)
        delete shapes[i];
}