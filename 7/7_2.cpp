#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::map;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    map<char, int> grades;
    Student_info stud;

    string::size_type maxSize = 0;
    while(read(cin, stud))
    {
        maxSize = max(maxSize, stud.name.size());
        students.push_back(stud);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i < students.size(); ++i)
    {
        cout << students[i].name 
             << string(maxSize + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
            cout << '\t' << letter_grade(final_grade);
            grades[letter_grade(final_grade)] += 1;
        }
        catch (domain_error e) {
            cout << e.what();
        }
        
        cout << endl;
    }

    for (map<char, int>::const_iterator it = grades.begin(); it != grades.end(); ++it)
    {
        cout << it->first << ": " << it->second << '\n';
    }

    return 0;
}