#include <iostream>

#include "NQueens.h"

int main() {
  int tests[] = {7, 9, 11, 13};
  for (const auto &t : tests) {
    const auto result = ods::placeQueens(t);
    std::cout << "N = " << result.n << ", soluciones = " << result.solutions
              << ", verificaciones = " << result.checks << "\n";

    // for (const auto &placement : result.placements) {
    //   for (int col : placement) {
    //     std::cout << col << ' ';
    //   }
    //   std::cout << '\n';
    // }
  }
  return 0;
}
