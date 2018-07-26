#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "4_5_funcs.h"

using std::istream;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

typedef vector<string>::size_type vec_sz;

istream& read_vector(istream& in, vector<string>& vec)
{
    if (in){
        string x;
        while(in >> x)
        {
            vec.push_back(x);
        }

        in.clear();
    }

    return in;
}

vec_sz word_count(const vector<string>& vec)
{
    return vec.size();
}

void word_occurrences(vector<string> vec)
{
    vec_sz vecSize = vec.size();
    if (vecSize == 0){
        cout << "Empty input list..." << endl;
        return;
    }
    cout << "Word: Count:" << endl;
    if (vecSize == 1){
        cout << vec[0] << " " << 1 << endl;
        return;
    }

    std::sort(vec.begin(), vec.end());
    vec_sz count = 1;
    for (vec_sz i = 0; i < vecSize - 1; i++)
    {
        if (vec[i] != vec[i+1]){
            cout << vec[i] << " " << count << endl;
            count = 1;
        }
        else {
            count++;
        }
    }
    if (vec[vecSize - 1] != vec[vecSize - 2]){
        // cout << vec[vecSize - 2] << " " << count << endl;
        cout << vec[vecSize - 1] << " " << 1 << endl;
    }
    else {
        cout << vec[vecSize - 1] << " " << count << endl; 
    }
}