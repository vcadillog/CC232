#include "FWideSwap.h"

#include <iostream>
#include <vector>

using namespace ods;

int main() {
  FWideSwap fw;

  std::vector<int> p = {4, 5, 7, 8, 3, 1, 2, 6};

  int K = 3;

  fw.loadPermutation(p);

  std::cout << fw;

  std::cout << "Permutacion inicial:\n";

  for (int x : fw.toVector()) {
    std::cout << x << " ";
  }

  std::cout << "\n\n";

  fw.solve(K);

  std::cout << "Permutacion minima:\n";

  for (int x : fw.toVector()) {
    std::cout << x << "\n";
  }

  std::cout << fw;
  return 0;
}
