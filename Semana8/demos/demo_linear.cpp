#include "LinearHashTable.h"
#include <iostream>

int main() {
  ods::LinearHashTable<int> t(8);
  for (int x : {7, 15, 23, 31, 39}) {
    t.add(x);
    std::cout << "loadFactor: " << t.loadFactor() << std::endl;
    std::cout << "size: " << t.size() << std::endl;
  };
  t.remove(23);
  std::cout << "loadFactor: " << t.loadFactor() << std::endl;
  std::cout << "size: " << t.size() << std::endl;
  t.add(47);
  std::cout << "loadFactor: " << t.loadFactor() << std::endl;
  std::cout << "size: " << t.size() << std::endl;

  std::cout << "LinearHashTable\n";
  std::cout << "size=" << t.size() << " capacity=" << t.capacity()
            << " activeLoad=" << t.loadFactor()
            << " occupiedLoad=" << t.occupiedFactor()
            << " tombstones=" << t.tombstoneCount() << "\n";
  std::cout << t.stats() << "\n";
}
