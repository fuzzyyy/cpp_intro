#include <iostream>
#include <list>
#include <vector>

#include "Student_info.h"
#include "fails.h"

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<Student_info> students;
    // list<Student_info> students;
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
    // list<Student_info> idiots;
    // idiots = extract_fails(students);    // indices
    idiots = extract_fails2(students);      // iterators
    // idiots = extract_fails3(students);   // list version


    cout << "passed:" << endl;
    print_students(students);
    cout << "failed:" << endl;
    print_students(idiots);
}