#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

// Student_info.h header file
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
void print_student(const Student_info&);
void print_students(const std::vector<Student_info>&);
void print_students(const std::list<Student_info>&);

std::vector<Student_info> extract_students(std::vector<Student_info>&,
										bool (const Student_info&));
#endif
