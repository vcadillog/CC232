#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

#include "FWideSwap.h"

using namespace std;

std::vector<int> solucionIngenua(std::vector<int> p, int K) {
  int n = p.size();
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 1; i < n; i++) {
      int posA = -1;
      int posB = -1;
      for (int j = 0; j < n; j++) {
        if (p[j] == i) {
          posA = j;
        }
        if (p[j] == i + 1) {
          posB = j;
        }
      }
      if (posA > posB && (posA - posB) >= K) {
        std::swap(p[posA], p[posB]);
        // std::cout << p[posA] << " " << p[posB];
        changed = true;
        break;
      }
    }
  }
  return p;
}

static std::vector<int> makePermutation(int n, std::mt19937 &rng) {
  std::vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  shuffle(p.begin(), p.end(), rng);
  return p;
}

template <typename Func>
double timeFunction(Func f, const std::vector<int> &p, int K, int iters = 5) {
  using clock = std::chrono::high_resolution_clock;

  auto start = clock::now();
  std::vector<int> result;

  for (int i = 0; i < iters; i++) {
    result = f(p, K);
  }

  auto end = clock::now();
  std::chrono::duration<double> diff = end - start;

  return diff.count() / iters;
}

int main() {
  std::mt19937 rng(12345);

  vector<int> sizes = {25, 50, 100, 150, 200};

  int K = 3;

  cout << "N" << setw(20) << "F-Wide Swap"<< setw(25)<< "Solución ingenua\n";

  for (int n : sizes) {
    auto p = makePermutation(n, rng);

    ods::FWideSwap fw;

    double t_fw = 0, t_ig = 0;

    {
      using clock = chrono::high_resolution_clock;

      auto start = clock::now();
      for (int i = 0; i < 5; i++) {
        fw.FWStoVector(p, K);
      }
      auto end = clock::now();
      t_fw = chrono::duration<double>(end - start).count() / 5.0;
    }

    {
      using clock = chrono::high_resolution_clock;

      auto start = clock::now();
      for (int i = 0; i < 5; i++) {
        solucionIngenua(p, K);
      }
      auto end = clock::now();
      t_ig = chrono::duration<double>(end - start).count() / 5.0;
    }

    cout << n << "," << setw(20) << t_fw << setw(15) << t_ig << "\n";
  }

  return 0;
}
