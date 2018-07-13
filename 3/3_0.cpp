#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "Please enter your midterm and final exam grades: ";
    double midtermGrade = 0.0;
    double finalGrade = 0.0;
    std::cin >> midtermGrade >> finalGrade;
    std::cout << std::endl;

    std::cout << "Now enter your homework grades: ";
    double x = 0;
    std::vector<double> hwGrades;
    while (std::cin >> x)
    {
        hwGrades.push_back(x);
    }

    std::vector<double>::size_type vectSize = hwGrades.size();

    if (vectSize == 0){
        std::cout << "No homework grades were given, exiting!" 
                  << std::endl;
        return 1;
    }

    std::sort(hwGrades.begin(), hwGrades.end());

    std::vector<double>::size_type mid = vectSize / 2;
    double median = 0;
    if (vectSize % 2 == 0){
        median = (hwGrades[mid] + hwGrades[mid-1])/2;
    }
    else{
        median = hwGrades[mid];
    }

    std::streamsize prec = std::cout.precision();
    std::cout << "Your final grade is: " << std::setprecision(3)
              << 0.2*midtermGrade + 0.4*finalGrade + 0.4*median
              << std::setprecision(prec) << std::endl;

    return 0;
}

