#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "4_0_Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif