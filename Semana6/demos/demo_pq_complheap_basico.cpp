#include <iostream>
#include <vector>

#include "Capitulo6.h"

namespace {

template <typename T>
void printVector(const std::vector<T> &xs, const char *label) {
  std::cout << label << ": [";
  for (std::size_t i = 0; i < xs.size(); ++i) {
    if (i != 0)
      std::cout << ", ";
    std::cout << xs[i];
  }
  std::cout << "]\n";
}

} // namespace

int main() {
  std::vector<int> base{4, 10, 7, 1, 3, 9};
  ods::PQ_ComplHeap<int> pq(base);

  std::cout << "PQ_ComplHeap construido con heapify de Floyd\n";
  printVector(base, "entrada");
  printVector(pq.data(), "heap interno");
  std::cout << "getMax() = " << pq.getMax() << "\n\n";

  for (int x : {12, 5, 14}) {
    pq.insert(x);
    std::cout << "insert(" << x << ")\n";
    printVector(pq.data(), "heap interno");
    std::cout << "max actual = " << pq.getMax() << "\n\n";
  }

  ods::PQ_ComplHeap<int> pq_copia(pq.data());
  while (!pq.empty()) {
    int y = pq.delMax();
    std::cout << "delMax() -> " << y << "\n";
    printVector(pq.data(), "heap interno");
  }

  printVector(pq_copia.data(), "heap interno");
  std::cout << "\nContando el número de intercambios\n";
  while (!pq_copia.empty()) {
    auto [y, count] = pq_copia.delMaxComentado();
    std::cout << "Número de intercambios:" << count << std::endl;
    std::cout << "delMax() -> " << y << "\n";
    printVector(pq_copia.data(), "heap interno");
    std::cout << std::endl;
  }

  std::vector<int> base2{};
  ods::PQ_ComplHeap<int> pq2(base2);
  std::cout << "\nContando el número de intercambios para inserciones para:\n";
  std::cout << "{ 40, 10, 70, 30, 90, 20, 80, 60 }\n";
  for (int x : {40, 10, 70, 30, 90, 20, 80, 60}) {
      std::size_t count = pq2.insertComentado(x);
    std::cout << "Número de intercambios:" << count << std::endl;
    std::cout << "insert(" << x << ")\n";
    printVector(pq2.data(), "heap interno");
    std::cout << "max actual = " << pq2.getMax() << "\n\n";
  }
}
