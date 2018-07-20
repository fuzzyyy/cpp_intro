#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::string::size_type maximum = 0;
    std::string::size_type minimum = input.max_size();

    if (std::cin >> input){
        maximum = input.size();
        minimum = input.size();

        while(std::cin >> input)
        {
            if (input.size() > maximum){
                maximum = input.size();
            }
            else if (input.size() < minimum){
                minimum = input.size();
            }
        }

    }
    else{
        return 0;
    }

    std::cout << "Maximum: " << maximum << std::endl
              << "Minimum: " << minimum << std::endl;

    return 0;
}

