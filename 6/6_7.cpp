#include <iostream>
#include <vector>

#include "compare_schemes.h"
#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<Student_info> did, didnt;
    Student_info student;
    while (read(cin, student))
    {
        did.push_back(student);
    }
    didnt = extract_students(did, did_all_hw);

    if (did.empty()) {
        cout << "No students did all the homework!" << "\n";
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homework!" << "\n";
        return 2;
    }

    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_grade, did, didnt);


    return 0;
}

