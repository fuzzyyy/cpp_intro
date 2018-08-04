#ifndef GUARD_fails_h
#define GUARD_fails_h

#include <list>
#include <vector>

#include "Student_info.h"

std::vector<Student_info> extract_fails_slow(std::vector<Student_info>&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

std::vector<Student_info> extract_fails_resize(std::vector<Student_info>&);

std::vector<Student_info> extract_fails_2pass(std::vector<Student_info>& students);
std::vector<Student_info> extract_fails_1pass(std::vector<Student_info>& students);
#endif