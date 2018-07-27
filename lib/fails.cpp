#include <list>
#include <vector>

#include "fails.h"
#include "grade.h"


using std::vector;
using std::list;

vector<Student_info> extract_fails(vector<Student_info>& students)
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

vector<Student_info> extract_fails2(vector<Student_info>& students)
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

list<Student_info> extract_fails3(list<Student_info>& students)
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