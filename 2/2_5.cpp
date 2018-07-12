#include <iostream>
#include <stdlib.h>

int main()
{
    const unsigned int squareA = 4;
    const unsigned int rectangleA = 5;
    const unsigned int rectangleB = 2;
    const int triangleA = 9;

    for (int i = 0; i < squareA; ++i)
    {
        for (int j = 0; j < squareA; ++j)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < rectangleA; ++i)
    {
        for (int j = 0; j < rectangleB; ++j)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < (triangleA+1)/2; ++i)
    {
        for (int j = 0; j < triangleA; ++j)
        {
            if (abs(j - triangleA/2) <= i){
                std::cout << '*';
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}

