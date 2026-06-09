#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Capitulo6.h"

namespace {

template <class T>
void printVector(const std::vector<T>& xs, const std::string& label) {
    std::cout << label << ": [";

    for (std::size_t i = 0; i < xs.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }

        std::cout << xs[i];
    }

    std::cout << "]\n";
}

void printState(const ods::Treap<int>& t, const std::string& label) {
    std::cout << "\n" << label << "\n";

    printVector(t.inorderKeys(), "inorden");
    printVector(t.levelOrderKeys(), "niveles");

    if (t.root()) {
        std::cout << "raiz: " << t.root()->key
                  << " | prioridad: " << t.root()->priority << "\n";
    } else {
        std::cout << "raiz: null\n";
    }

    std::cout << "isBST: " << std::boolalpha << t.isBST() << "\n";
    std::cout << "isHeapByPriority: " << t.isHeapByPriority() << "\n";
    std::cout << "isTreap: " << t.isTreap() << "\n";
    std::cout << "parent_links: " << t.hasValidParentLinks() << "\n";
}

void printSearchResult(const std::string& name, const ods::Treap<int>::Node* node) {
    std::cout << name << ": ";

    if (node) {
        std::cout << node->key << " | prioridad=" << node->priority << "\n";
    } else {
        std::cout << "null\n";
    }
}

} // namespace

int main() {
    ods::Treap<int> t(232);

    const std::vector<std::pair<int, std::uint64_t>> fixed{
        {50, 50}, {30, 30}, {70, 70},
        {20, 20}, {40, 40}, {60, 60}, {80, 80}
    };

    std::cout << "Bloque 10 - Parte A: Treap con prioridades fijas\n";

    for (const auto& [key, priority] : fixed) {
        t.addWithPriority(key, priority);

        std::cout << "\ninsertada clave=" << key
                  << " prioridad=" << priority << "\n";

        printState(t, "estado despues de insertar");
    }

    std::cout << "\nArbol final Parte A:\n";
    std::cout << t.asciiArt() << "\n";

    std::cout << "\nBloque 10 - Parte B: bubbleUpCount\n";

    ods::Treap<int> b(232);
    const std::vector<std::pair<int, std::uint64_t>> bubbleSeq{
        {100, 100}, {90, 90}, {80, 80}, {70, 70}, {60, 60}
    };

    for (const auto& [key, priority] : bubbleSeq) {
        const std::size_t rotations = b.addWithPriorityCount(key, priority);

        std::cout << "clave=" << key
                  << " prioridad=" << priority
                  << " rotaciones=" << rotations
                  << " raiz=" << b.root()->key << "\n";

        printVector(b.levelOrderKeys(), "niveles");
    }

    std::cout << "\nBloque 10 - Parte C: trickleDownCount y removeCount\n";

    ods::Treap<int> c(232);
    for (const auto& [key, priority] : fixed) {
        c.addWithPriority(key, priority);
    }

    for (int key : {50, 20, 70}) {
        const std::size_t rotations = c.removeCount(key);

        std::cout << "\neliminada clave=" << key
                  << " rotaciones=" << rotations << "\n";

        printState(c, "estado despues de eliminar");
    }

    std::cout << "\nBloque 10 - Parte D: busqueda ordenada\n";

    ods::Treap<int> d(232);
    for (const auto& [key, priority] : fixed) {
        d.addWithPriority(key, priority);
    }

    printSearchResult("findEQ(40)", d.findEQ(40));
    printSearchResult("findEQ(35)", d.findEQ(35));
    printSearchResult("lowerBound(35)", d.lowerBound(35));
    printSearchResult("lowerBound(40)", d.lowerBound(40));
    printSearchResult("upperBound(40)", d.upperBound(40));
    printSearchResult("upperBound(75)", d.upperBound(75));

    return 0;
}
