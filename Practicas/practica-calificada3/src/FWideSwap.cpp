#include "FWideSwap.h"

#include <cmath>
#include <vector>

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
  int vi = getAt(i);
  int vj = getAt(j);
  if (i > j) {
    std::swap(i, j);
    std::swap(vi, vj);
  }
  eraseAt(j);
  eraseAt(i);

  insertAt(i, vj);
  insertAt(j, vi);
}
void FWideSwap::solve(int K) {
  int n = size();

  std::vector<int> pos(n + 2, 0);

  {
    auto p = toVector();
    for (int i = 0; i < n; i++) {
      pos[p[i]] = i;
    }
  }

  bool changed = true;
  while (changed) {
    changed = false;

    for (int a = 1; a < n; a++) {
      int posA = pos[a];
      int posB = pos[a + 1];
      if (posA > posB && (posA - posB) >= K) {
        swapPositions(posA, posB);

        pos[a] = posB;
        pos[a + 1] = posA;

        changed = true;
        break;
      }
    }
  }
}

std::vector<int> FWideSwap::FWStoVector(std::vector<int> p, int K) {
    clear();
    std::cout << "after clear size=" << size() << '\n';
    loadPermutation(p);
    solve(K);
    return toVector();
}
} // namespace ods
