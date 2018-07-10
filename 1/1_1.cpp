#include <iostream>

int main()
{
    const std::string greeting = "Greetings";
    const std::string message = greeting + " mr. " + "Vimerino!";
    const std::string kekel = "KEK"; // + " " + "KAK"; // literal + literal
                                                   // fails to compile
    std::cout << message << std::endl << kekel;
    return 0;
}
