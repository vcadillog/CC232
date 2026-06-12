#include "FWideSwap.h"
#include <algorithm>
#include <cassert>
#include <vector>

using namespace ods;

int main() {
  FWideSwap fw;
  // Casos de atcoder
  assert(fw.FWStoVector({4, 2, 3, 1}, 2) == (std::vector<int>{2, 1, 4, 3}));

  assert(fw.FWStoVector({5, 4, 3, 2, 1}, 1) ==
         (std::vector<int>{1, 2, 3, 4, 5}));

  assert(fw.FWStoVector({4, 5, 7, 8, 3, 1, 2, 6}, 3) ==
         (std::vector<int>{1, 2, 6, 7, 5, 3, 4, 8}));

  // Casos propios
  assert(fw.FWStoVector({6, 4, 2, 1, 5, 3}, 2) ==
         (std::vector<int>{4, 3, 2, 1, 6, 5}));

  assert(fw.FWStoVector({7, 3, 5, 1, 6, 2, 4}, 4) ==
         (std::vector<int>{5, 2, 4, 1, 7, 3, 6}));

  assert(fw.FWStoVector({5, 2, 7, 1, 6, 3, 4}, 3) ==
         (std::vector<int>{3, 2, 7, 1, 6, 4, 5}));

  // 5,3,1,2,4 k=2
  // 4,3,1,2,5
  // 4,2,1,3,5
  // 3,2,1,4,5
  assert(fw.FWStoVector({5,3,1,2,4}, 2) ==
         (std::vector<int>{3,2,1,4,5}));
}
