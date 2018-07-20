#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> input;
    std::vector<bool> checked;
    std::string x;

    std::cout << "Input: ";
    while (std::cin >> x)
    {
        input.push_back(x);
        checked.push_back(0);
    }

    for (int i = 0; i < input.size(); i++)
    {
        int count = 0;
        if (checked[i] == 0){
            for (int j = i; j < input.size(); j++)
            {
                if (input[i] == input[j]){
                    count++;
                    checked[j] = 1;
                }
            }                
            std::cout << "The word " << input[i]
                      << " has been found " << count << " times." 
                      << std::endl;
        }
    }

    return 0;
}
