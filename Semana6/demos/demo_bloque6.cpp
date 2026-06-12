#include <functional>
#include <iostream>
#include <vector>

#include "PQ_ComplHeap_heapifyFloyd.h"
#include "PQ_ComplHeap_insert.h"
#include "PQ_ComplHeap_percolateUp.h"
#include "PQ_ComplHeap_percolateDown.h"

namespace {

template <class T>
void printVector(const std::vector<T>& xs, const char* label) {
    std::cout << label << ": [";

    for (std::size_t i = 0; i < xs.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }

        std::cout << xs[i];
    }

    std::cout << "]\n";
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

template <class T, class Compare>
std::size_t buildByInsertions(const std::vector<T>& input,
                              std::vector<T>& output,
                              Compare comp) {
    output.clear();

    std::size_t totalSwaps = 0;

    for (const T& value : input) {
        output.push_back(value);

        // MOD-A6-B6: se usa la version instrumentada del Bloque 3.
        totalSwaps += ods::complHeapPercolateUpCount(
            output,
            output.size() - 1,
            comp
        );
    }

    return totalSwaps;
}

template <class T, class Compare>
std::size_t buildByFloydCount(std::vector<T>& values, Compare comp) {
    if (values.size() < 2) {
        return 0;
    }

    std::size_t totalSwaps = 0;

    // MOD-A6-B6: Floyd procesa desde el ultimo nodo interno hasta la raiz.
    for (std::size_t i = values.size() / 2; i-- > 0;) {
        totalSwaps += ods::complHeapPercolateDownCount(
            values,
            values.size(),
            i,
            comp
        );
    }

    return totalSwaps;
}

} // namespace

int main() {
    const std::vector<int> input = {
        4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89
    };

    const std::less<int> comp;

    std::vector<int> heapByInsertions;
    std::vector<int> heapByFloyd = input;

    const std::size_t swapsInsertions =
        buildByInsertions(input, heapByInsertions, comp);

    const std::size_t swapsFloyd =
        buildByFloydCount(heapByFloyd, comp);

    std::cout << "Bloque 6 - construccion de heap\n";
    std::cout << "Convencion: max-heap usando std::less<int>\n\n";

    printVector(input, "arreglo inicial");
    printVector(heapByInsertions, "heap por inserciones");
    printVector(heapByFloyd, "heap por Floyd");

    std::cout << "\n";

    std::cout << "intercambios por inserciones: "
              << swapsInsertions << "\n";

    std::cout << "intercambios por Floyd: "
              << swapsFloyd << "\n";

    std::cout << "heap por inserciones valido: "
              << (isValidHeap(heapByInsertions, comp) ? "verdadero" : "falso")
              << "\n";

    std::cout << "heap por Floyd valido: "
              << (isValidHeap(heapByFloyd, comp) ? "verdadero" : "falso")
              << "\n";

    std::cout << "\nInterpretacion: ambos arreglos representan heaps validos, "
              << "aunque no necesariamente tienen la misma forma interna.\n";

    return 0;
}
