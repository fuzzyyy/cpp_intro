// #include <algorithm>
// #include <stdexcept>
// #include <vector>

// #include "median.h"

// using std::vector;

// double median(vector<double> vec)
// {
//     typedef vector<double>::size_type vec_sz;
//     vec_sz size = vec.size();

//     if (size == 0){
//         throw std::domain_error("median of empty vector");
//     }

//     std::sort(vec.begin(), vec.end());
//     vec_sz mid = size / 2;
//     if (size % 2 == 0){
//         return (vec[mid] + vec[mid-1])/2.0;
//     }
//     else {
//         return vec[mid];
//     }
// }