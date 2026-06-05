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
  std::vector<int> base{};
  ods::PQ_ComplHeap<int> pq(base);

  std::cout << "PQ_ComplHeap construido con heapify de Floyd\n";
  printVector(base, "entrada");
  printVector(pq.data(), "heap interno");
  std::cout << "\nBloque 3:\n";

  std::cout << "\nContando el número de intercambios para inserciones para:\n";
  std::cout << "{ 40, 10, 70, 30, 90, 20, 80, 60 }\n";
  for (int x : {40, 10, 70, 30, 90, 20, 80, 60}) {
      std::size_t count = pq.insertComentado(x);
    std::cout << "Número de intercambios:" << count << std::endl;
    std::cout << "insert(" << x << ")\n";
    printVector(pq.data(), "heap interno");
    std::cout << "max actual = " << pq.getMax() << "\n\n";
  }
}
