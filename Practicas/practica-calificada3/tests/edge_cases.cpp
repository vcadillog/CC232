#include "FWideSwap.h"
#include <algorithm>
#include <cassert>
#include <vector>

using namespace ods;

int main() {
  FWideSwap fw;
  assert(fw.FWStoVector({}, 10) == (std::vector<int>{}));

  assert(fw.FWStoVector({1}, 1) == (std::vector<int>{1}));
  assert(fw.FWStoVector({1}, 5) == (std::vector<int>{1}));

  assert(fw.FWStoVector({1, 2}, 1) == (std::vector<int>{1, 2}));
  assert(fw.FWStoVector({1, 2}, 2) == (std::vector<int>{1, 2}));

  assert(fw.FWStoVector({2, 1}, 1) == (std::vector<int>{1, 2}));

  assert(fw.FWStoVector({2, 1}, 2) == (std::vector<int>{2, 1}));

  std::vector<int> sorted = {1, 2, 3, 4, 5};
  for (int K = 1; K <= 5; K++)
    assert(fw.FWStoVector(sorted, K) == sorted);

  assert(fw.FWStoVector({5, 4, 3, 2, 1}, 1) ==
         (std::vector<int>{1, 2, 3, 4, 5}));

  assert(fw.FWStoVector({5, 4, 3, 2, 1}, 10) ==
         (std::vector<int>{5, 4, 3, 2, 1}));

  assert(fw.FWStoVector({3, 1, 2}, 3) == (std::vector<int>{3, 1, 2}));
  assert(fw.FWStoVector({3, 1, 2}, 0) == (std::vector<int>{1, 2, 3}));
}
