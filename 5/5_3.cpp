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
    typedef list<Student_info> new_type;
    new_type students;
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
    
    new_type idiots;
    idiots = extract_fails(students);


    cout << "passed:" << endl;
    print_students(students);
    cout << "failed:" << endl;
    print_students(idiots);
}