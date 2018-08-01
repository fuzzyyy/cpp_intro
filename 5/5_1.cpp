#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "strvect_utils.h"

using std::cout;
using std::cin;
using std::endl;

using std::isspace;

using std::sort;

using std::string;
using std::vector;

struct row{
    string str;
    string left;
    string right;
    vector<string>::size_type perm;
};

vector<string> split(const string&);
vector<row> perms(const vector<string>&);
bool compare(const row&, const row&);
void print_vect(const vector<row>&);
void transform_row(row&);

int main()
{
    // 'row' is custom structure holding the following:
    //      permutation string,
    //      permutation number (number of word shifts)
    //      left side of the final expression
    //      right side of the final expression
    // 
    // 
    // the input data has to go through this pipeline:
    // 
    // -getline(s) produces string with input --> split(s) --> vector<string>
    // 
    // -vector<string> v --> perms(v) --> append new rows to the 'rows' vector
    //                                   (which holds all rows)
    // 
    // -sort the rows
    // 
    // -transform the permutation string into two parts: left and right
    // -also find the longest left side (for the formatting)
    // 
    // -print out all the rows with nice formatting


    vector< vector<string> > rowsVectorized;
    vector<row> rows;
    string x;

    // store input lines as vector<string>
    while (getline(cin, x))
    {
        rowsVectorized.push_back(split(x));
    }

    // create permutations
    for (vector< vector<string> >::size_type i = 0; i < rowsVectorized.size(); ++i)
    {
        vector<row> v = perms(rowsVectorized[i]);
        rows.insert(rows.end(), v.begin(), v.end());
    }

    // sort permutations
    sort(rows.begin(), rows.end(), compare);

    // break permutation into left and right side
    string::size_type maxsize = 0;
    for (vector<row>::iterator i = rows.begin(); i != rows.end(); ++i)
    {
        transform_row(*i);
        if (i->left.size() > maxsize) {
            maxsize = i->left.size();
        }
    }

    // final print
    const string separator = " --- ";
    for (vector<row>::const_iterator iter = rows.begin(); iter != rows.end(); iter++)
    {
        cout << string(maxsize - iter->left.size(), ' ') << iter->left 
             << separator << iter->right << endl;
    }


    return 0;
}

vector<string> split(const string& s)
{
    vector<string> ret;

    string::size_type i = 0;

    while (i != s.size())
    {
        while (i != s.size() && isspace(s[i]))
        {
            ++i;
        }

        string::size_type j = i;
        while (j != s.size() && !isspace(s[j]))
        {
            ++j;
        }

        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}

vector<row> perms(const vector<string>& words)
{
    vector<row> ret;
    for (vector<string>::size_type i = 0; i < words.size(); i++)
    {
        row r;
        r.str = words[i];
        r.perm = i;
        for (vector<string>::size_type j = 1; j < words.size(); j++)
        {
            r.str += " ";
            r.str += words[(i+j)%words.size()];
        }
        ret.push_back(r);
    }
    return ret;
}

bool compare(const row& a, const row& b)
{
    return a.str < b.str;
}

void print_vect(const vector<row>& vec)
{
    for (vector<row>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout << i->perm << ": " << i->str << endl;
    }
}

void transform_row(row& r)
{
    if (r.perm == 0) {
        r.left = "";
        r.right = r.str;
        return;
    }

    vector<string> vec = split(r.str);
    r.left = vec[vec.size() - r.perm];
    for (vector<string>::size_type i = vec.size() - r.perm + 1; i < vec.size(); ++i)
    {
        r.left += " " + vec[i];
    }
    r.right = vec[0];
    for (vector<string>::size_type i = 1; i < vec.size() - r.perm; ++i)
    {
        r.right += " " + vec[i];
    }
}
