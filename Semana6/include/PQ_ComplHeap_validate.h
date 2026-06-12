#pragma once

#include <cstddef>
#include <vector>

#include "PQ_ComplHeap_macro.h"

namespace ods {

// MOD-A6-B5: valida explicitamente la propiedad heap en un arreglo implicito.
// La convencion es: si comp(padre, hijo) es true, entonces el hijo domina al padre
// y la propiedad heap esta rota.
template <class T, class Compare>
bool complHeapIsValid(const std::vector<T>& a, Compare comp) {
    for (std::size_t i = 0; i < a.size(); ++i) {
        const std::size_t left = pqLeftChild(i);
        const std::size_t right = pqRightChild(i);

        if (left < a.size() && comp(a[i], a[left])) {
            return false;
        }

        if (right < a.size() && comp(a[i], a[right])) {
            return false;
        }
    }

    return true;
}

} // namespace ods
