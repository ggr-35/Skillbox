#pragma once

/*Команда scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения. При выполнении в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами.

Команда hemostat принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.

Команда tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом выводится в консоль.

Команда suture — хирургическая игла, которая делает шов между двумя указанными точками.

Операция всегда начинается с команды scalpel и заканчивается командой suture. Для окончания работы программы их параметры-точки должны совпасть.

*/

struct p
{
double x,y;
};

struct section
{

    p pone, ptwo;

    void scalpel(section s)
    {
        std::cout << "scalpel!" << std::endl;
    }

    void hemostat(section s)
    {
        std::cout << "hemostat!" << std::endl;
    }

    void tweezers(section s)
    {
        std::cout << "tweezers!" << std::endl;
    }

    void suture(section s1, section s2)
    {
        std::cout << "suture!" << std::endl;
        coincidence(s1, s2);
    }

    void coincidence(section s1, section s2)
    {
        //if ((s.pone.x == s.ptwo.x) && (s.pone.y == s.ptwo.y))
        if ((s1.pone.x == s2.pone.x) && (s1.pone.y == s2.pone.y))
            std::cout << "The operation is OVER";
        else
            std::cout << "The operation is NOT OVER";
     std::cout << std::endl;
     exit(EXIT_SUCCESS);
    }

};