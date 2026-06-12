#pragma once

#include <algorithm>
#include <functional>
#include <vector>

#include "PQ_ComplHeap_heapifyFloyd.h"
#include "PQ_ComplHeap_percolateDown.h"

namespace ods {

namespace detail {

template <class T, class Compare>
void heapSortWithComparator(std::vector<T>& a, Compare comp) {
    if (a.size() < 2) {
        return;
    }

    // MOD-A6-B7: construir el heap inicial usando Floyd.
    complHeapHeapifyFloyd(a, comp);

    // MOD-A6-B7: mover repetidamente la raiz al final del rango activo.
    for (std::size_t n = a.size(); n > 1; --n) {
        std::swap(a[0], a[n - 1]);
        complHeapPercolateDown(a, n - 1, 0, comp);
    }
}

} // namespace detail

template <class T, class Compare = std::less<T>>
void heapSort(std::vector<T>& a,
              Compare comp = Compare{},
              bool ascending = true) {
    if (ascending) {
        // MOD-A6-B7: con std::less<T> se construye max-heap y queda ascendente.
        detail::heapSortWithComparator(a, comp);
        return;
    }

    // MOD-A6-B7: para descendente se invierte la relacion de prioridad.
    auto reversedComp = [comp](const T& left, const T& right) mutable -> bool {
        return comp(right, left);
    };

    detail::heapSortWithComparator(a, reversedComp);
}

template <class T, class Compare = std::less<T>>
std::vector<T> heapSorted(std::vector<T> a,
                          Compare comp = Compare{},
                          bool ascending = true) {
    heapSort(a, comp, ascending);
    return a;
}

} // namespace ods
