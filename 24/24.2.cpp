/*
Реализуйте простую программу по вычислению ближайшего дня рождения.

В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: 
вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день. 
Сигналом окончания ввода дней рождения является “end” введённое в качестве имени.

После этого программа вычисляет ближайший день рождения по отношению к 
текущему времени и выводит его на экран вместе с именем в удобном, локальном формате - месяц/день. 
Если день рождения уже был в этом году, данные о пользователе пропускаются. 
Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом. 
Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.

Советы и рекомендации

Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.

Что оценивается

Корректность работы программы.
*/


#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
 
struct birthdays
{
   std::string name;
   std::tm data;
}new_birthday;

std::vector<birthdays> vec;
std::time_t t_now = std::time(nullptr);
std::tm now = *std::localtime(&t_now);

void vec_print()
{
   if(vec[0].data.tm_mon == now.tm_mon && vec[0].data.tm_mday == now.tm_mday)
      std::cout << "Today the birthday is celebrated : " << std::endl;
         
   for (int i = 0; i < vec.size(); i++)
      if(vec[i].data.tm_mon == vec[0].data.tm_mon 
         && vec[i].data.tm_mday == vec[0].data.tm_mday)
         std::cout << vec[i].name << " " << std::put_time(&vec[i].data,"%y/%m/%d") << std::endl;
}
   
void input()
{
   while (true)
   {
      std::cout << "Enter the name: ";
      std::cin >> new_birthday.name;
      if(new_birthday.name != "end")
      {
         std::cout << "Enter the year: ";
         std::cin >> new_birthday.data.tm_year;
         new_birthday.data.tm_year -= 1900;
         std::cout << "Enter the mon: ";
         std::cin >> new_birthday.data.tm_mon;
         new_birthday.data.tm_mon -= 1;
         std::cout << "Enter the day: ";
         std::cin >> new_birthday.data.tm_mday;
         vec.push_back(new_birthday);
      }else
         break;
   } 
}

void del_vec()
{
    for (int i = 0; i < vec.size(); i++)
   {
      if((vec[i].data.tm_mon < now.tm_mon) || (vec[i].data.tm_mon == now.tm_mon && vec[i].data.tm_mday < now.tm_mday))
      {
         vec.erase(vec.begin() + i);
         --i;
      }
   }
}

void sort()
{
   for (int i = 0; i < vec.size() - 1; i++)
   {
      for (int j = 1; j < vec.size(); j++)
      {
         if(vec[j - 1].data.tm_mon > vec[j].data.tm_mon 
         || (vec[j - 1].data.tm_mon == vec[j].data.tm_mon && vec[j - 1].data.tm_mday > vec[j].data.tm_mday))
         {
            birthdays buff = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = buff;
         }
      }
   }
}

int main()
{
   input();
   del_vec();
   sort();
   vec_print();

}