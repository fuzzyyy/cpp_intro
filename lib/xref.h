#ifndef GUARD_xref_h
#define GUARD_xref_h

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "string_utils.h"

std::map<std::string, std::vector<int> >
    xref_old(std::istream&, std::vector<std::string> (*)(const std::string& s) = split);

std::map<std::string, std::vector<int> >
    xref(std::istream&, std::vector<std::string> (*)(const std::string& s) = split);

#endif
