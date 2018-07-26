#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "4_6_grade.h"
#include "4_6_Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info stud;

    string::size_type maxSize = 0;
    while(read(cin, stud))
    {
        maxSize = max(maxSize, stud.name.size());
        students.push_back(stud);
    }

    sort(students.begin(), students.end(), compare);

    streamsize prec = cout.precision();
    for (vector<Student_info>::size_type i = 0; i < students.size(); ++i)
    {
        cout << students[i].name 
             << string(maxSize + 1 - students[i].name.size(), ' ');
        cout << setprecision(3) << students[i].grade << setprecision(prec);   
        cout << endl;
    }

    return 0;
}