#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "compare_schemes.h"
#include "grade.h"
#include "median.h"
#include "average.h"

using std::find;
using std::remove_if;
using std::transform;

using std::ostream;

using std::back_inserter;

using std::domain_error;

using std::vector;
using std::string;

bool did_all_hw(const Student_info& s)
{
    return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

void write_analysis(ostream& out,
                    const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did)
                << ", median(didnt) = " << analysis(didnt) << "\n";
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

double median_analysis(const vector<Student_info>& vec)
{
    vector<double> grades;

    transform(vec.begin(), vec.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average_analysis(const vector<Student_info>& vec)
{
    vector<double> grades;

    transform(vec.begin(), vec.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& vec)
{
    vector<double> grades;

    transform(vec.begin(), vec.end(), back_inserter(grades), optimistic_median_grade);
    return median(grades);
}
