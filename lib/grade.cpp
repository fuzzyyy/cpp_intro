#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

#include "grade.h"
#include "median.h"
#include "average.h"

using std::remove_copy;
using std::back_inserter;
using std::vector;
using std::domain_error;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw std::domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    }
    catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median_grade(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0);
    }
    else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}
