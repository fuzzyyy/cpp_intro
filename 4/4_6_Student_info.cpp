#include <iostream>

#include "4_6_Student_info.h"
#include "4_6_grade.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& in, Student_info& stud)
{
    double midterm, final;
    in >> stud.name >> midterm >> final;
    if (in) {
        vector<double> vec;
        read_hw(in, vec);
        stud.grade = grade(midterm, final, vec);
    }
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