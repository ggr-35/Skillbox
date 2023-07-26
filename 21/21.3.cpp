/*Реализуйте структуру двумерного математического вектора и основные операции над ним. Обе координаты вектора (x и y) должны быть вещественными числами.

Начиная работу с программой, пользователь вводит команду. Затем в зависимости от команды пользователь вводит аргументы. Это могут быть как векторы, так и обычные скалярные значения. Результат помещается в стандартный вывод. Это тоже может быть или вектор, или скаляр.

Реализуйте в виде отдельных функций операции:

сложение двух векторов — команда add;
вычитание двух векторов — команда subtract;
умножение вектора на скаляр — команда scale;
нахождение длины вектора — команда length;
нормализация вектора — команда normalize.
Советы и рекомендации
Для выбора команды используйте конструкцию вида if (operation == "add"). Тут так и напрашиваются отдельные функции для каждой операции.
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>


struct math_vec_2D
{
  double x_1;
  double y_1;
  double x_2;
  double y_2;
} vec;


math_vec_2D vec_add(math_vec_2D a, math_vec_2D b)
{
    math_vec_2D c;
    c.x_1 = a.x_1 + b.x_1;
    c.y_1 = a.y_1 + b.y_1;
    c.x_2 = a.x_2 + b.x_2;
    c.y_2 = a.y_2 + b.y_2;

    std::cout << c.x_1 << c.y_1 << c.x_2 << c.y_2;
    return c;
}

math_vec_2D vec_sub(math_vec_2D a, math_vec_2D b)
{
    math_vec_2D c;
    c.x_1 = a.x_1 - b.x_1;
    c.y_1 = a.y_1 - b.y_1;
    c.x_2 = a.x_2 - b.x_2;
    c.y_2 = a.y_2 - b.y_2;

    std::cout << c.x_1 << c.y_1 << c.x_2 << c.y_2;
    return c;
}

math_vec_2D vec_scale(math_vec_2D a, double scal)
{
   a.x_1*= scal;
   a.y_1*= scal;
   a.x_2*= scal;
   a.y_2*= scal;
   std::cout << a.x_1 << a.y_1 << a.x_2 << a.y_2;
   return a;
}

double vec_length(math_vec_2D a)
{
    return sqrt(pow(a.x_2 - a.x_1,2) + pow(a.y_2 - a.y_1,2));
}

math_vec_2D vec_normalize(math_vec_2D a)
{
    double len = vec_length(a);
    a.x_1/= len;
    a.x_2/= len;
    a.y_1/= len;
    a.y_2/= len;
    std::cout << a.x_1 << a.y_1 << a.x_2 << a.y_2;
    return a;
}


int main()
{

    std::cout << "Enter the first vector(x1; y1; x2; y2): "; std::cin >> vec.x_1 >> vec.y_1 >> vec.x_2 >> vec.y_2;

    std::cout << "Enter the command: ";
    std::string command;
    std::cin >> command;

    if(command == "add")
    {
        math_vec_2D vec_2;
        std::cin >> vec_2.x_1 >> vec_2.y_1 >> vec_2.x_2 >> vec_2.y_2;
        vec_add(vec, vec_2);
        
    }
    else if (command == "subtract")
    {
        math_vec_2D vec_2;
        std::cin >> vec_2.x_1 >> vec_2.y_1 >> vec_2.x_2 >> vec_2.y_2;
        vec_sub(vec, vec_2);
    }
    else if (command == "scale")
    {
        double scal;
        std::cout << "Enter the scale: "; std::cin >> scal;
        vec_scale(vec, scal);
    }
    else if (command == "length")
    {
       std::cout << vec_length(vec);
    }
    else if (command == "normalize")
    {
        vec_normalize(vec);
    }
    else
        std::cerr << "Error !" << std::endl;  
}
