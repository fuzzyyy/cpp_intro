#ifndef GUARD_fails_h
#define GUARD_fails_h

#include <list>
#include <vector>

#include "Student_info.h"

std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::vector<Student_info> extract_fails2(std::vector<Student_info>&);
std::list<Student_info> extract_fails3(std::list<Student_info>&);

#endif