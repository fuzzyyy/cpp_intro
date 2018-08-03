#include <numeric>

#include "average.h"

using std::vector;
using std::accumulate;

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
