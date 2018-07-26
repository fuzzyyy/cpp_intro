#include <vector>
#include "4_7_average.h"

using std::vector;

typedef vector<double>::size_type vec_sz;

double average(const vector<double>& vec)
{
    double sum = 0;
    vec_sz vecSize = vec.size();
    for (vec_sz i = 0; i < vecSize; i++)
    {
        sum += vec[i];
    }
    
    return sum/vecSize;
}