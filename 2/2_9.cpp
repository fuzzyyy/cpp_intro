#include <iostream>

int main() 
{
    int a = 0;
    int b = 0;

    std::cout << "Please enter a number: "; 
    std::cin >> a;
    std::cout << std::endl;

    std::cout << "Please enter another number: "; 
    std::cin >> b;
    std::cout << std::endl;

    if (a == b){ 
        std::cout << "They are equal :-o "; 
    }

    else if (a > b){ 
        std::cout << "The first number " << a 
        << " was greater than the second number " << b; 
    } else{
        std::cout << "The second number " << b 
            << " was greater than the first number " << a; 
    }

    std::cout << std::endl;
    return 0; 
}
