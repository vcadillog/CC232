#include <iostream>

#include "BaseConversion.h"

struct Test {
  int n;
  int base;
};

int main() {

  Test tests[] = {{5, 2},    {15, 2},    {31, 8},  {12345, 8},
                  {255, 16}, {1024, 16}, {100, 3}, {999, 7}};
  for (const auto &t : tests) {
    std::cout << "Numero: " << t.n << " Base: " << t.base << '\n';

    std::cout << "  Recursivo : " << ods::toBaseRecursive(t.n, t.base) << '\n';

    std::cout << "  Iterativo : " << ods::toBaseIterative(t.n, t.base) << '\n';

    std::cout << '\n';
  }
  return 0;
}
