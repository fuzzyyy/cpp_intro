#include <iostream>
#include <string>

int main()
{ 
    {
        const std::string s = "retezec";
        std::cout << s << std::endl;
        {
            const std::string s = "jiny retezec";
            std::cout << s << std::endl;
        };
    }
    return 0;
}
