#include <iostream>
#include <stdlib.h>

int main()
{
    const unsigned int squareA = 4;
    const unsigned int rectangleA = 5;
    const unsigned int rectangleB = 10;
    const unsigned int triangleA = 9;

    for (int i = 0; i < squareA; ++i)
    {
        if (i == 0 || i == squareA - 1){
            std::string tmp(squareA, '*');
            std::cout << tmp;
        }
        else{
            std::string tmp(squareA-2, ' ');
            std::cout << '*' << tmp << '*';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    for (int i = 0; i < rectangleA; ++i)
    {
        if (i == 0 || i == rectangleA - 1){
            std::string tmp(rectangleB, '*');
            std::cout << tmp;
        }
        else{
            std::string tmp(rectangleB - 2, ' ');
            std::cout << '*' << tmp << '*';
        }
        std::cout << std::endl;
    }

    for (int i = triangleA - 1; i > 0; i--)
    {
        std::string pad(i, ' ');
        std::string innerPad(2*(triangleA - 1 -i), ' ');
        std::cout << pad << '*' << innerPad << '*' << std::endl;
    }
    {
        std::string tmp(2*triangleA, '*');
        std::cout << tmp << std::endl;
    }

    return 0;
}

