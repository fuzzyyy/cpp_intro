#include <iostream>
#include <list>
#include <vector>

#include "Student_info.h"
#include "fails.h"
#include "grade.h"

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<Student_info> students;
    Student_info stud;

    while (read(cin, stud))
    {
        students.push_back(stud);
    }

    cout << endl;
    cout << "before extraction:" << endl;
    print_students(students);

    cout << endl;
    cout << "after extraction:" << endl;
    vector<Student_info> idiots;
    // idiots = extract_fails_2pass(students);
    idiots = extract_students(students, pgrade);


    cout << "passed:" << endl;
    print_students(students);
    cout << "failed:" << endl;
    print_students(idiots);
}