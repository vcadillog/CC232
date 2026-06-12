#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

#include "PQ_ComplHeap_macro.h"

namespace ods {

template <typename T, typename Compare>
std::size_t complHeapPercolateDown(std::vector<T> &a, std::size_t n,
                                   std::size_t i, Compare comp) {
  // MOD-A6-B2: se usa pqIsInternal para expresar que solo se baja si hay hijo
  // izquierdo.
  while (pqIsInternal(i, n)) {
    std::size_t c = pqLeftChild(i);

    // MOD-A6-B2: si existe hijo derecho, se compara contra el hijo izquierdo.
    if (pqHasRightChild(i, n)) {
      const std::size_t r = pqRightChild(i);
      if (comp(a[c], a[r])) {
        c = r;
      }
    }

    if (!comp(a[i], a[c])) {
      break;
    }

    std::swap(a[i], a[c]);
    i = c;
  }

  return i;
}

template <class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T> &a, std::size_t n,
                                        std::size_t i, Compare comp) {
  std::size_t counter = 0;
  while (pqInHeap(pqLeftChild(i), n)) {
    std::size_t c = pqLeftChild(i);
    const std::size_t r = pqRightChild(i);
    if (pqInHeap(r, n) && comp(a[c], a[r])) {
      c = r;
    }
    if (!comp(a[i], a[c])) {
      break;
    }
    std::swap(a[i], a[c]);
    i = c;
    counter++;
  }
  return counter;
}
} // namespace ods
