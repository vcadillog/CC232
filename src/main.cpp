#include <iostream>
#include <vector>
#include "count_ones.h"

// Función que usa countOnes1
std::vector<int> countOnesArray1(unsigned int n) {
    std::vector<int> result;
    result.reserve(n + 1);
    for (unsigned int i = 0; i <= n; ++i) {
        result.push_back(countOnes1(i));
    }
    return result;
}

// Función que usa countOnes2
std::vector<int> countOnesArray2(unsigned int n) {
    std::vector<int> result;
    result.reserve(n + 1);
    for (unsigned int i = 0; i <= n; ++i) {
        result.push_back(countOnes2(i));
    }
    return result;
}

// Función auxiliar para imprimir vector en formato [a, b, c]
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i + 1 < arr.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    unsigned int n = 10;

    auto arr1 = countOnesArray1(n);
    auto arr2 = countOnesArray2(n);

    std::cout << "Usando countOnes1:\n";
    printArray(arr1);

    std::cout << "\nUsando countOnes2:\n";
    printArray(arr2);

    return 0;
}
