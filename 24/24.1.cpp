/*
Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.

Пользователь взаимодействует с программой с помощью команд:

Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название задачи, 
над которой он планирует сейчас работать.
Если уже была начата какая-то другая задача, предыдущая должна быть автоматически завершена и начата новая.
Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено. 
Также выводится название текущей выполняемой задачи, если таковая имеется.
Команда exit выходит из программы.
Советы и рекомендации

Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>



struct task
{
   std::string name = "unnamed";
   std::time_t t_start = 0;
   std::time_t t_spent = 0;
}new_task;

std::vector<task> tasks;

void end()
{  
   tasks.back().t_spent = std::difftime(std::time(nullptr), tasks.back().t_start);
}

void begin()
{
  if(!tasks.empty())
   end();

  std::cout << "Enter the task name: ";
  std::cin >> new_task.name;
  new_task.t_start = std::time(nullptr);
  tasks.push_back(new_task);
}


void status()
{
   std::cout << "#########################" << std::endl;

   for (int i = 0; i < tasks.size(); i++)
   {  
      if(tasks[i].t_spent != 0)
      {
         tasks[i].t_spent -= static_cast<std::time_t>(10800);// <-- костыль ?
         std::tm local = *std::localtime(&tasks[i].t_spent);
         std::cout << tasks[i].name << " - " << std::put_time(&local,"%H:%M:%S") << std::endl;
      }
   }
      if(tasks.back().t_spent == 0)
         std::cout << "Current running task: " << tasks.back().name << std::endl;

   std::cout << "#########################" << std::endl;
}




int main()
{
   int command = 0;

   while (true)
   {
      std::cout << "Enter thhe command: 1 - begin, 2 - end, 3 -  status, 4 - exit ";
      std::cin >> command;

      if(command == 1)
         begin();
      else if (command == 2 && !tasks.empty())
      {
         end();
      }
      else if (command == 3 && !tasks.empty())
      {
         status();
      }
      else if (command == 4)
         exit(EXIT_SUCCESS);
      else
         std::cout << "ERROR!" << std::endl;
      
   }
}