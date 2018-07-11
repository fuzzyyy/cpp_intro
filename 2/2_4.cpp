#include <iostream>

int main()
{
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;

    std::cout << std::endl;

    unsigned int padding = 0;
    std::cout << "Please enter padding value: ";
    std::cin >> padding;

    const unsigned int rows = 2*padding + 3;

    std::cout << std::endl;

    const std::string greeting = "Hi, " + name;
    const std::string::size_type greetSize = greeting.size();
    const unsigned int cols = greetSize + 2*padding + 2;

    const unsigned int spacesSize = greetSize + 2*padding;
    const std::string spaces(spacesSize, ' ');
    const std::string paddingSpaces(padding, ' ');

    std::cout << std::endl;

    for (unsigned int row = 0; row < rows; ++row)
    {
        std::string::size_type col = 0;
        while (col < cols)
        {
            if (row == 0 || row == rows -1 
                || col == 0 || col == cols - 1){
                std::cout << "*";
                col++;
            }
            else if (row == padding + 1){
                std::cout << paddingSpaces << greeting << paddingSpaces;
                col += greetSize + 2*padding;
            }
            else {
                std::cout << spaces;
                col += spacesSize;
            }
        } 
        std::cout << std::endl;
    }
}

