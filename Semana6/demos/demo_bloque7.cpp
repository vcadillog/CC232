#include <functional>
#include <iostream>
#include <map>
#include <vector>

#include "Capitulo6.h"

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

template <class T>
std::map<T, int> countValues(const std::vector<T>& xs) {
    std::map<T, int> counts;

    for (const T& value : xs) {
        ++counts[value];
    }

    return counts;
}

template <class T>
void printCounts(const std::vector<T>& xs, const char* label) {
    const std::map<T, int> counts = countValues(xs);

    std::cout << label << ": {";

    bool first = true;
    for (const auto& entry : counts) {
        if (!first) {
            std::cout << ", ";
        }

        first = false;
        std::cout << entry.first << " -> " << entry.second;
    }

    std::cout << "}\n";
}

} // namespace

int main() {
    const std::vector<int> input{5, 1, 5, 3, 8, 2, 8, 0};

    std::vector<int> ascending = input;
    std::vector<int> descending = input;

    ods::heapSort(ascending, std::less<int>{}, true);
    ods::heapSort(descending, std::less<int>{}, false);

    std::cout << "Bloque 7 - heapSort ascendente y descendente\n\n";

    printVector(input, "entrada");
    printVector(ascending, "salida ascendente");
    printVector(descending, "salida descendente");

    std::cout << "\nEvidencia de repetidos\n";
    printCounts(input, "conteo entrada");
    printCounts(ascending, "conteo ascendente");
    printCounts(descending, "conteo descendente");

    std::cout << "\nInterpretacion: los valores repetidos no se eliminan. "
              << "Aparecen dos 5 y dos 8 en ambas salidas.\n";

    return 0;
}
