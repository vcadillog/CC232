#include <cassert>
#include <vector>

#include "count_ones.h"

//Pruebas adicionales
int main() {
    assert(countOnes1(0u) == 0);
    assert(countOnes1(0b11110000u) == 4);
    assert(countOnes2(0b11110000u) == 4);
    return 0;
}
