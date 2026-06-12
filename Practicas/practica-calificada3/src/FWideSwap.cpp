#include "FWideSwap.h"
#include <iostream>

namespace ods {

void FWideSwap::loadPermutation(const std::vector<int> &p) {
  for (int x : p) {
    pushBack(x);
  }
}

void FWideSwap::swapPositions(int i, int j) {
  if (i == j)
    return;

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
    for (int i = 0; i < n; i++)
      pos[p[i]] = i;
  }

  int a = 1;
  while (a < n) {
    int posA = pos[a];
    int posB = pos[a + 1];

    if (posA > posB && (posA - posB) >= K) {
      swapPositions(posA, posB);
      pos[a] = posB;
      pos[a + 1] = posA;
      if (a > 1)
        a--;
    } else {
      a++;
    }
  }
}

void FWideSwap::solvePrint(int K) {
  int n = size();

  std::vector<int> pos(n + 2, 0);
  {
    auto p = toVector();
    for (int i = 0; i < n; i++)
      pos[p[i]] = i;
  }

  int a = 1;
  while (a < n) {
    int posA = pos[a];
    int posB = pos[a + 1];

    if (posA > posB && (posA - posB) >= K) {
      auto p = toVector();
      for (int x : p) {
        std::cout << x << " ";
      }
      swapPositions(posA, posB);
      pos[a] = posB;
      pos[a + 1] = posA;
      std::cout << "intercambio: " <<p[posA] << " " << p[posB] << std::endl;
      if (a > 1)
        a--;
    } else {
      a++;
    }
  }
}

std::vector<int> FWideSwap::FWStoVector(std::vector<int> p, int K) {
  clear();
  loadPermutation(p);
  solve(K);
  return toVector();
}

} // namespace ods
