#include <iostream>
#include <string>
#include <vector>
#include <iomanip> //manipulators
#include <ios> //streamsize

int main()
{
    std::vector<std::string> students;
    std::vector<double> grades;
    const unsigned int numOfGrades = 3;
    unsigned short grade = 0;
    std::string name;
    while (std::cin >> name)
    {
        students.push_back(name);
        unsigned int sum = 0;
        for (int i = 0; i < numOfGrades; ++i)
        {
            std::cin >> grade;
            sum += grade; 
        }
        grades.push_back((double)sum/numOfGrades);
    }

    std::streamsize prec = std::cout.precision();
    for (int i = 0; i < students.size(); i++)
    {
        std::cout << std::setprecision(4)
                  << students[i] << ": " << grades[i] << std::endl;
    }
    std::cout << std::setprecision(prec);
}
