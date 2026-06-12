#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "Capitulo4.h"

int main() {
  {
    // AAA: Arrange
    const std::string expr = "7%2";
    const std::string expr2 = "5%";

    // AAA: Act
    const auto eval = ods::evaluateExpression(expr);

    // AAA: Assert
    assert(eval.rpn == "7 2 %");
    std::cout << eval.value << '\n';
    assert(eval.value == 1);
    try {
      const auto eval2 = ods::evaluateExpression(expr2);
    } catch (const std::runtime_error &e) {
    }
  }

  return 0;
}
