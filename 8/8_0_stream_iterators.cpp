#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    cout << "input:\n";
    vector<int> vec;
    copy(istream_iterator<int>(cin),
         istream_iterator<int>(),
         back_inserter(vec));

    cout << "output:\n";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
