#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

int digits(int num)
{   
    int i = 0;
    while (num > 0)
    {
        num = num / 10;
        i++;
    }

    return i;
}

int main()
{
    const int threshold = 100;
    int padding1 = digits(threshold);
    int padding2 = digits(threshold*threshold) + 1; // 1 extra space to separate them

    for (int i = 0; i <= threshold; ++i)
    {
        cout << setw(padding1) << i << setw(padding2) << i*i << endl;
    }
    
    return 0;
}