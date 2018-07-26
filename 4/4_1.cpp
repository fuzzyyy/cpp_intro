#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    int a = __INT_MAX__;
    // long b = __INT_MAX__ + 1l;
    std::string::size_type b = 1;
    std::cout << std::max(a, b) << std::endl;
    // std::cout << std::max((long)a, b) << std::endl;
    // std::cout << std::max(a, (int)b) << std::endl;
    return 0;
}