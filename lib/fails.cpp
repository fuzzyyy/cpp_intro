#include <list>
#include <vector>

#include "fails.h"
#include "grade.h"


using std::vector;
using std::list;

vector<Student_info> extract_fails_slow(vector<Student_info>& students)
{
    vector<Student_info> ret;

    vector<Student_info>::size_type i = 0;
    while(i < students.size())
    {
        if (fgrade(students[i])){
            ret.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else {
            ++i;
        }
    }

    return ret;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> ret;
    vector<Student_info>::iterator iter = students.begin();
    while(iter != students.end())
    {
        if (fgrade(*iter)){
            ret.push_back(*iter);
            students.erase(iter);
        }
        else {
            ++iter;
        }
    }

    return ret;   
}

list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> ret;
    list<Student_info>::iterator iter = students.begin();
    while(iter != students.end())
    {
        if (fgrade(*iter)){
            ret.push_back(*iter);
            iter = students.erase(iter);
        }
        else {
            ++iter;
        }
    }

    return ret;   
}

// damn I'm a dumbfuck :D
// vector<Student_info> extract_fails_resize(vector<Student_info>& students)
// {
//     vector<Student_info>::size_type successfulStudents = 0;
//     vector<Student_info> ret;

//     vector<Student_info>::iterator iter = students.begin();
//     while (iter != students.end())
//     {
//         if (!fgrade(*iter)) {
//             iter = students.insert(students.begin(), *iter);
//             successfulStudents++;
//         }
//         else {
//             ret.push_back(*iter);
//         }

//         ++iter;
//     }
//     students.resize(successfulStudents);
//     return ret;
// }

vector<Student_info> extract_fails_resize(vector<Student_info>& students)
{
    vector<Student_info>::size_type successCount = 0;
    vector<Student_info> ret;

    for (vector<Student_info>::size_type i = 0; i < students.size(); ++i)
    {
        if (fgrade(students[i])) {
            ret.push_back(students[i]);
        } 
        else {
            students[successCount] = students[i];
            successCount++;
        }
    }

    students.resize(successCount);

    return ret;
}
