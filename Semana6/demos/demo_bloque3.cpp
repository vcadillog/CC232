#include <functional>
#include <iostream>
#include <vector>

#include "PQ_ComplHeap_percolateUp.h"

namespace {

template <class T>
void printVector(const std::vector<T>& values) {
    std::cout << "[";

    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }

        std::cout << values[i];
    }

    std::cout << "]";
}

template <class T, class Compare>
bool isValidHeap(const std::vector<T>& values, Compare comp) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        const std::size_t left = 2 * i + 1;
        const std::size_t right = 2 * i + 2;

        if (left < values.size() && comp(values[i], values[left])) {
            return false;
        }

        if (right < values.size() && comp(values[i], values[right])) {
            return false;
        }
    }

    return true;
}

} // namespace

int main() {
    std::vector<int> heap;
    const std::vector<int> input = {40, 10, 70, 30, 90, 20, 80, 60};
    const std::less<int> comp;

    std::cout << "Bloque 3 - conteo de intercambios en percolateUp\n";
    std::cout << "Convencion: max-heap usando std::less<int>\n\n";

    for (const int value : input) {
        heap.push_back(value);

        const std::size_t swaps =
            ods::complHeapPercolateUpCount(heap, heap.size() - 1, comp);

        const bool valid = isValidHeap(heap, comp);

        std::cout << "insertado=" << value
                  << " | intercambios=" << swaps
                  << " | heap=";

        printVector(heap);

        std::cout << " | propiedad_heap="
                  << (valid ? "verdadero" : "falso")
                  << "\n";
    }

    return 0;
}
