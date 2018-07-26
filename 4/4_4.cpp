#include <iomanip>
#include <ios>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::fixed;
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
    const double start = -1.0;
    const double stop = 10.0;
    const double increment = 0.05;

    int padding1 = digits((int)stop) + 3 + 1; // 3 digits after decimal point, 1 minus sign
    int padding2 = digits((int)(stop*stop)) + 3 + 1; // 1 space separation
    double i = start;
    
    streamsize prec = cout.precision();
    cout << fixed;
    cout << setprecision(3);
    while(i <= stop)
    {
        cout << setw(padding1) << i << setw(padding2) << i*i << endl;
        i += increment;
    }
    cout << setprecision(prec);

    return 0;   
}