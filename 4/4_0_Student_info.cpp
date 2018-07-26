#include <iostream>

#include "4_0_Student_info.h"

using std::istream;
using std::vector;

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