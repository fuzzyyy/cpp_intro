#include <iostream>

int main()
{
    const unsigned int paddingHori = 5;
    const unsigned int paddingVert = 2;
    const unsigned int rows = 2*paddingHori + 3;

    std::string name;
    std::cin >> name;

    const std::string greeting = "Hi, " + name;
    const std::string::size_type greetSize = greeting.size();
    const unsigned int cols = greetSize + 2*paddingVert + 2;

    std::cout << std::endl;

    for (unsigned int row = 0; row < rows; ++row)
    {
        std::string::size_type col = 0;
        while (col < cols)
        {
            if (row == 0 || row == rows -1 || col == 0 || col == cols - 1){
                std::cout << "*";
                col++;
            }
            else if (row == paddingHori + 1 && col == paddingVert + 1){
                std::cout << greeting;
                col += greetSize;
            }
            else {
                std::cout << " ";
                col++;
            }
        } 
        std::cout << std::endl;
    }
}

