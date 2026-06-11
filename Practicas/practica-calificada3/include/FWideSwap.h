#pragma once
#include "ImplicitTreap.h"

namespace ods {

class FWideSwap : public ImplicitTreap<int> {
public:
  FWideSwap() = default;

  void loadPermutation(const std::vector<int> &p);

  void swapPositions(int i, int j);

  void solve(int K);
};

} // namespace ods
