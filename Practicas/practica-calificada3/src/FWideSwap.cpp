#include "FWideSwap.h"

#include <cmath>
#include <iostream>

namespace ods {

void FWideSwap::loadPermutation(const std::vector<int> &p) {
  for (int x : p) {
    pushBack(x);
  }
}
void FWideSwap::swapPositions(int i, int j) {
  if (i == j) {
    return;
  }

  std::vector<int> arr = toVector();

  std::swap(arr[i], arr[j]);

  clear();

  for (int x : arr) {
    pushBack(x);
  }
}
void FWideSwap::solve(int K) {
  bool changed = true;

  while (changed) {
    changed = false;

    auto p = toVector();

    int n = static_cast<int>(p.size());

    for (int a = 1; a < n; a++) {
      int posA = -1;
      int posB = -1;

      for (int i = 0; i < n; i++) {
        if (p[i] == a) {
          posA = i;
        }

        if (p[i] == a + 1) {
          posB = i;
        }
      }

      if (posA > posB && std::abs(posA - posB) >= K) {
        swapPositions(posA, posB);

        changed = true;

        break;
      }
    }
  }
}
} // namespace ods
