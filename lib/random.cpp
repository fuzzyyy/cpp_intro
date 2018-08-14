#include <cstdlib>
#include <stdexcept>

using std::domain_error;

#include "random.h"

int nrand(int n)
{
    if (n < 0 || n > RAND_MAX) {
        throw domain_error("Argument to nrand is out of range!");
    }

    const int bucketSize = RAND_MAX / n;
    int r;

    do {
        r = rand() / bucketSize;
    }
    while (r >= n);

    return r;
}
