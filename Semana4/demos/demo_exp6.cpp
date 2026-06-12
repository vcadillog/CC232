#include <iostream>
#include <vector>

#include "BankSimulation.h"

struct TestCase {
  int nWin;
  int servTime;
  unsigned seed;
};

int main() {
  std::vector<TestCase> tests = {{2, 10, 12345U}, {3, 10, 12345U},
                                 {5, 10, 12345U}, {3, 20, 12345U},
                                 {3, 10, 54321U}, {4, 15, 98765U}};

  for (const auto &test : tests) {
    const auto result = ods::simulate(test.nWin, test.servTime, test.seed);

    std::cout << "nWin = " << test.nWin << ", servTime = " << test.servTime
              << ", seed = " << test.seed << '\n';

    std::cout << "totalArrivals = " << result.totalArrivals << '\n';

    std::cout << "totalServed = " << result.totalServed << '\n';

    std::cout << "colas finales = ";

    if (!result.timeline.empty()) {
      const auto &last = result.timeline.back();

      for (std::size_t i = 0; i < last.queues.size(); ++i) {
        std::cout << '[';

        for (std::size_t j = 0; j < last.queues[i].size(); ++j) {
          if (j)
            std::cout << ',';
          std::cout << last.queues[i][j];
        }

        std::cout << ']';

        if (i + 1 < last.queues.size()) {
          std::cout << ' ';
        }
      }
    }

    std::cout << "\n\n";
  }

  return 0;
}
