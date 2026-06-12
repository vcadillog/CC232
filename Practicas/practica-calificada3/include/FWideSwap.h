#pragma once
#include "ImplicitTreap.h"
#include <vector>

namespace ods {

class FWideSwap : public ImplicitTreap<int> {
public:
  FWideSwap() = default;
  void loadPermutation(const std::vector<int> &p);
  void swapPositions(int i, int j);
  void solve(int K);
  void solvePrint(int K);
  std::vector<int> FWStoVector(std::vector<int> p, int K);
};
} // namespace ods
