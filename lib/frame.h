#ifndef GUARD_frame_h
#define GUARD_frame_h

#include <string>
#include <vector>

std::vector<std::string>::size_type max_width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);

std::vector<std::string> vcat(const std::vector<std::string>& top,
                              const std::vector<std::string>& bottom);
std::vector<std::string> vcat2(const std::vector<std::string>& top,
                               const std::vector<std::string>& bottom);
std::vector<std::string> hcat(const std::vector<std::string>& left,
                              const std::vector<std::string>& right);

std::vector<std::string> center(const std::vector<std::string>&);

#endif
