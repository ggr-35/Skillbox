#include <iostream>

using std::string, std::cout, std::cin, std::endl, std::time_t, std::vector;

class Point
{
public:
    int x = 1;
    int y = 1;


};

class Window
{
private:

    Point mainPoint;
    int height = 5;
    int width = 10;

public:

    void move(int x, int y)
    {
        mainPoint.x += x;
        mainPoint.y += y;
    }

    void resize(int newHeight, int newWidth)
    {
        height = newHeight;
        width = newWidth;
    }
    
    Point getMainPoint()
    {
        return mainPoint;
    }

    int getHeight()
    {
        return height;
    }

    int getWidth()
    {
        return width;
    }

};


class Display
{
private:
    Window window;
    int height = 50;
    int width = 80;

public:

    void windMove(int x = 1, int y = 1)
    {
        if ((x + window.getMainPoint().x < height) && (y + window.getMainPoint().y < width))
            window.move(x, y);
        else
            exit(EXIT_FAILURE);
    }

    void winResize(int newHeight, int newWidth)
    {
        if(newHeight > height)
            newHeight = height;
        
        if(newWidth > width)
            newWidth = width;

        window.resize(newHeight, newWidth);
    }

    void display()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {   
                if (i == 0 || i == height - 1)
                    cout << '-';
                else if (j == 0 || j == width - 1)
                    cout << '|';
                else if ((j >= window.getMainPoint().x) && (j < (window.getMainPoint().x + window.getWidth()))
                      && (i >= window.getMainPoint().y) && (i < (window.getMainPoint().y + window.getHeight())))
                    cout << '1';
                else 
                    cout << '0';
            }
        }
            cout << endl;
            cout << endl;
    }

    void gerWinSize()
    {   
        cout << window.getHeight() << window.getWidth();
    }

};



int main()
{   
    Display display;
    display.display();
    display.winResize(25, 50);
    display.display();
    display.windMove(40, 10);
    display.display();
    display.winResize(100, 100);
    display.display();
    display.gerWinSize();
}   