#pragma once

#include <stdexcept>
#include <vector>
#include <iostream>

#include "PQ_ComplHeap_percolateDown.h"

namespace ods {

template <class T, class Compare>
T complHeapDelMax(std::vector<T>& a, Compare comp) {
  if (a.empty()) {
    throw std::out_of_range("delMax() sobre heap vacio");
  }
  T ans = a.front();
  a.front() = a.back();
  a.pop_back();
  if (!a.empty()) {
    complHeapPercolateDown(a, a.size(), 0, comp);
  }
  return ans;
}

template <class T, class Compare>
T complHeapDelMaxComentado(std::vector<T>& a, Compare comp) {
  if (a.empty()) {
    throw std::out_of_range("delMax() sobre heap vacio");
  }
  T ans = a.front();
  a.front() = a.back();
  a.pop_back();
  if (!a.empty()) {
    int count = complHeapPercolateDownCount(a, a.size(), 0, comp);
    std::cout << "Número de intercambios:" << count << std::endl;
  }
  return ans;
}

}  // namespace ods
