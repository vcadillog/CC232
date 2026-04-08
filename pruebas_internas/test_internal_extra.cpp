#include <cassert>
#include <vector>

#include "count_ones.h"

int main() {
    for (unsigned int x : {0u, 1u, 7u, 31u, 255u, 256u, 1023u}) {
        assert(countOnes1(x) == countOnes2(x));
    }

    return 0;
}
