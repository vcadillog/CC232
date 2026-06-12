#include "FWideSwap.h"
#include <algorithm>
#include <cassert>
#include <vector>

using namespace ods;

int main() {
    FWideSwap fw;
  // Casos de atcoder
  assert(fw.FWStoVector({4, 2, 3, 1}, 2) == (std::vector<int>{2, 1, 4, 3}));

  assert(fw.FWStoVector({5, 4, 3, 2, 1}, 1) == (std::vector<int>{1, 2, 3, 4, 5}));

  assert(fw.FWStoVector({4, 5, 7, 8, 3, 1, 2, 6}, 3) ==
         (std::vector<int>{1, 2, 6, 7, 5, 3, 4, 8}));
}
