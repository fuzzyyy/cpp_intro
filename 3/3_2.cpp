#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

int main()
{
    cout << "Please enter dem numberz :D " << endl;
    int x = 0;
    vector<int> numberz;
    while (cin >> x)
    {
        numberz.push_back(x);
    }

    if (numberz.size() < 4){
        cout << "NEED AT LEAST 4 NUMBERZ, EXITING!" << endl;
        return 1;
    }

    sort(numberz.rbegin(), numberz.rend());
    // or sort it in ascending order and print out in reverse order

    std::vector<int>::size_type vectSize = numberz.size();
    std::vector<int>::size_type stepSize = 0;
    if (vectSize % 4 == 3){
        stepSize = vectSize / 4 + 1;
    }
    else{
        stepSize = vectSize / 4;
    }
    
    cout << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i+1 << ":" << endl;
        for (int j = stepSize*i; j < stepSize*(i+1); j++)
        {
            cout << numberz[j] << endl;
        }
        cout << endl;
    }

    cout << "4:" << endl;
    for (int i = stepSize*3; i < vectSize; i++)
    {
        cout << numberz[i] << endl;
    }

    return 0;
}
