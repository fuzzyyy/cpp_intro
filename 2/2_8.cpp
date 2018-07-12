#include <iostream>
#include <iomanip>

int main()
{
    const int range = 10;
    int product = 1;
    for (int i = 1; i < range; ++i)
    {
        product *= i;
    }
    std::cout << product << std::endl;
    
    return 0;
}
