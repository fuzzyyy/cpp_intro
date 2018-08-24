#ifndef GUARD_compare_schemes
#define GUARD_compare_schemes

#include "Student_info.h"
#include "median.h"

#include <iostream>
#include <string>
#include <vector>

bool did_all_hw(const Student_info&);
void write_analysis(std::ostream&,
                    const std::string&,
                    double(const std::vector<Student_info>&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);
void write_analysis(std::ostream&,
                    const std::string&,
                    double(const Student_info&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);
double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);

template<class Function>
double analysis(const std::vector<Student_info>& vec,
                Function grading_func(const Student_info&))
{
    std::vector<double> grades;
    transform(vec.begin(), vec.end(), back_inserter(grades), grading_func);
    return median(grades);
}


template<class Function>
void write_analysis(std::ostream& out,
                    const std::string& name,
                    double grading_func(const Student_info&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did, grading_func)
        << ", median(didnt) = " << analysis(didnt, grading_func) << "\n";
}
#endif
