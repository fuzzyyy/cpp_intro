#ifndef GUARD_funcs_h
#define GUARD_funcs_h

#include <iostream>
#include <string>
#include <vector>

std::istream& read_vector(std::istream&, std::vector<std::string>&);

std::vector<std::string>::size_type word_count(const std::vector<std::string>&);

void word_occurrences(std::vector<std::string>);

#endif