#include <algorithm>

#include "string_utils.h"

using std::string;
using std::vector;
using std::isspace;

using std::find_if;
using std::equal;


bool space(char);
bool not_space(char);

string::const_iterator url_beg(string::const_iterator a, string::const_iterator b);
string::const_iterator url_end(string::const_iterator a, string::const_iterator b);
bool not_url_char(char);

// isspace is overloaded (widechars...)
// space is helper function, so compiler knows which isspace we want
bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& s)
{
    vector<string> ret;
    string::const_iterator i = s.begin();
    while (i != s.end())
    {
        i = find_if(i, s.end(), not_space);

        string::const_iterator j = find_if(i, s.end(), space);

        if (i != s.end()) {
            ret.push_back(string(i, j));
        }

        i = j;
    }

    return ret;
}

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

vector<string> find_urls(const string& s)
{
    vector<string> ret;

    string::const_iterator beg = s.begin();
    string::const_iterator end = s.end();

    while (beg != end) 
    {
        beg = url_beg(beg, end);

        if (beg != end) {
            string::const_iterator after = url_end(beg, end);
            ret.push_back(string(beg, after));
            beg = after;
        }

    }


    return ret;
}

bool not_url_char(char c)
{
    static const string urlChars = "~;/?:@=&$-_.+!*'(),";

    return !(isalnum(c)
             || find(urlChars.begin(), urlChars.end(), c) != urlChars.end());
}

string::const_iterator url_end(string::const_iterator begin,
                               string::const_iterator end)
{
    return find_if(begin, end, not_url_char);
}

string::const_iterator url_beg(string::const_iterator begin,
                               string::const_iterator end)
{
    static const string sep = "://";

    string::const_iterator i = begin;
    while( (i = search(i, end, sep.begin(), sep.end())) != end)
    {
        if (i != begin && i + sep.size() != end) {
            
            string::const_iterator beg = i;
            while (beg != begin && isalpha(beg[-1]))
            {
                --beg;
            }

            // if there was a valid character before the separator
            // and the very next character after the separator is valid
            // return iterator pointing to the beginning of the protocol
            if (beg != i && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }

        // skip the found separator in case it wasn't part of an url
        i += sep.size();
    }

    return end;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}
