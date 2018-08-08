#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

#include "Student_info.h"

using std::istream;
using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::stable_partition;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& in, Student_info& stud)
{
    in >> stud.name >> stud.midterm >> stud.final;

    read_hw(in, stud.homework);
    return in;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in){
        hw.clear();

        double x = 0;

        while(in >> x)
        {
            hw.push_back(x);
        }

        in.clear();
    }
    return in;
}

void print_student(const Student_info& s)
{
    cout << s.name << " " << s.midterm << " " << s.final << " ";
    for (vector<Student_info>::size_type i = 0; i < s.homework.size(); ++i)
    {
        cout << s.homework[i] << " ";
    }
    cout << endl;
}

void print_students(const vector<Student_info>& vec)
{
    for (vector<Student_info>::size_type i = 0; i < vec.size(); ++i)
    {
        print_student(vec[i]);
    }
}

void print_students(const list<Student_info>& students)
{
    for (list<Student_info>::const_iterator iter = students.begin();
         iter != students.end(); ++iter)
    {
        print_student(*iter);
    }
}

vector<Student_info> extract_students(vector<Student_info>& students,
                                    bool criterion(const Student_info&))
{
    vector<Student_info>::iterator iter =
            stable_partition(students.begin(), students.end(), criterion);
    vector<Student_info> ret(iter, students.end());
    students.erase(iter, students.end());

    return ret;
}
