#include <iostream>
#include <iomanip>

int main()
{
    const int range = 10;
    for (int i = 1; i < range; i++)
    {
        for (int j = 1; j < range; j++)
        {
            std::cout << std::setw(3) << i*j;
        }
        std::cout << std::endl;
    }

    return 0;
}
