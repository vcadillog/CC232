#include "FWideSwap.h"
#include <algorithm>
#include <cassert>
#include <vector>

using namespace ods;

static std::vector<int> runFWS(std::vector<int> p, int K) {
    FWideSwap fw;
    fw.loadPermutation(p);
    fw.solve(K);
    return fw.toVector();
}

int main() {
    assert(runFWS({1}, 1) == (std::vector<int>{1}));
    assert(runFWS({1}, 5) == (std::vector<int>{1}));

    assert(runFWS({1, 2}, 1) == (std::vector<int>{1, 2}));
    assert(runFWS({1, 2}, 2) == (std::vector<int>{1, 2}));

    assert(runFWS({2, 1}, 1) == (std::vector<int>{1, 2}));

    assert(runFWS({2, 1}, 2) == (std::vector<int>{2, 1}));

    std::vector<int> sorted = {1, 2, 3, 4, 5};
    for (int K = 1; K <= 5; K++)
        assert(runFWS(sorted, K) == sorted);

    assert(runFWS({5, 4, 3, 2, 1}, 1) == (std::vector<int>{1, 2, 3, 4, 5}));

    assert(runFWS({5, 4, 3, 2, 1}, 10) == (std::vector<int>{5, 4, 3, 2, 1}));

    assert(runFWS({3, 1, 2}, 3) == (std::vector<int>{3, 1, 2}));
}
