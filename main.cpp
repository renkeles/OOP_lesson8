#include <iostream>
#include "DivisionByZero.h"
#include "Ex.h"
#include "OffTheField.h"

void task1()
{
    try
    {
        double result = my::div(10, 0);
        std::cout << result << std::endl;
    }
    catch (const DivisionByZero& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
}

void task2()
{
    Bar a;
    int b;

    try
    {
        while (true)
        {
            std::cin >> b;
            if (b == 0)
                break;
            a.set(b);
        }
    }
    catch (const Ex& e)
    {
        std::cout << e.m_x << std::endl;
    }
}

void task3()
{
    int x = 0, y = 0;
    Robot r;

    while (true)
    {
        std::cin >> x >> y;

        if (x == 0 && y == 0)
            break;

        try
        {
            r.move(x, y);
        }
        catch (const IllegalCommand& e)
        {
            std::cerr << e.getInfo() << std::endl;
        }
        catch (const OffTheField& e)
        {
            std::cerr << e.getInfo() << std::endl;
        }
    }
}

int main() {

    //task1();
    //task2();
    task3();


    return 0;
}
