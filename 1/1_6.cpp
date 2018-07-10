#include <iostream>
#include <string>

int main()
{
    std::cout << "What's your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name
              << std::endl << "And what's your name? ";
    std::cin >> name;
    std::cout << "Hello, " << name
              << "; nice to meet you, too!" << std::endl;
    return 0;
}

