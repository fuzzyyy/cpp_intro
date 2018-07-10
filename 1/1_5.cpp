#include <iostream>
#include <string>

int main()
{
    {
        std::string s = "retezec";
        {
            std::string x = s + ", opravdu";
            std::cout << s << std::endl;
            std::cout << x << std::endl;
        }
    }
    return 0;
}
