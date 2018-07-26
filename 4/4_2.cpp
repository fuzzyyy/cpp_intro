#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main()
{
    cout << setw(6) << "Value" << setw(7) << "Square" << endl;
    for (int i = 0; i <= 100; ++i)
    {
        cout << setw(6) << i << setw(7) << i*i << endl;
    }

    return 0;
}