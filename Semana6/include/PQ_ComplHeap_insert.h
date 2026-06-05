#pragma once

#include <vector>
#include <iostream>

#include "PQ_ComplHeap_percolateUp.h"

namespace ods {

template <class T, class Compare>
void complHeapInsert(std::vector<T> &a, const T &e, Compare comp) {
  a.push_back(e);
  complHeapPercolateUp(a, a.size() - 1, comp);
}

template <class T, class Compare>
std::size_t complHeapInsertComentado(std::vector<T> &a, const T &e, Compare comp) {
  a.push_back(e);
  std::size_t count = complHeapPercolateUpCount(a, a.size() - 1, comp);
  return count;
}
} // namespace ods
