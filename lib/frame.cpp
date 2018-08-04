#include <string>
#include <vector>

#include "frame.h"

using std::string;
using std::vector;

string::size_type max_width(const vector<string>& vec)
{
    string::size_type maxSize = 0;
    for(vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        if (iter->size() > maxSize){
            maxSize = iter->size();
        }
    }    
    return maxSize;
}

vector<string> frame(const vector<string>& vec)
{
    vector<string> ret;
    string::size_type maxWidth = max_width(vec);
    string border = string(maxWidth + 4, '*');
    ret.push_back(border);
    for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        ret.push_back("* " + (*iter) + string(maxWidth - iter->size(), ' ') + " *");
    }
    ret.push_back(border);

    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret = top;
    for (vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter)
    {
        ret.push_back(*iter);
    }

    return ret;
}

vector<string> vcat2(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    string::size_type maxLenght = max_width(left);

    vector<string>::const_iterator i = left.begin();
    vector<string>::const_iterator j = right.begin();

    while (i != left.end() || j != right.end())
    {
        string tmp;
        if (i != left.end()){
            tmp = (*i);
            i++;
        }
        // else {
        //     tmp += string(maxLenght + 1, ' ');
        // }
        tmp += string(maxLenght + 1 - tmp.size(), ' ');

        if (j != right.end()) {
            tmp += (*j);
            j++;
        }

        ret.push_back(tmp);
    }

    return ret;
}

std::vector<std::string> center(const std::vector<std::string>& vec)
{
    string::size_type maxLenght = max_width(vec);

    vector<string> ret;

    string::size_type leftPadding = 0;
    for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        leftPadding = (maxLenght - iter->size())/2;
        ret.push_back("*" + string(leftPadding, ' ') + (*iter)
                      + string(maxLenght - iter->size() - leftPadding, ' ') + "*"); 
    }

    return ret;
}
