#ifndef LIB_STRINGUTILS_H
#define LIB_STRINGUTILS_H

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string&);
bool is_palindrome(const std::string&);
std::vector<std::string> find_urls(const std::string&);
bool bracketed(const std::string&);
bool space(char);
bool not_space(char);

template<class T>
void split(const std::string& str, T out)
{
    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end())
    {
        i = std::find_if(i, str.end(), not_space);

        iter j = std::find_if(i, str.end(), space);

        if (i != str.end())
        {
            *out++ = std::string(i, j);
        }

        i = j;
    }
}

#endif
