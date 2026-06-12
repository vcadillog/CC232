#include <iomanip>
#include <iostream>
#include <vector>

#include "Capitulo5.h"
#include "Capitulo6.h"

struct Row {
    std::string estructura;
    std::string operacionPrincipal;
    std::string propiedad;
    std::string eficiente;
    std::string noConviene;
    std::string evidencia;
};

int main() {
    const std::vector<int> xs{8, 3, 10, 1, 6, 14, 4, 7, 13};

    ods::PQ_ComplHeap<int> pq;
    ods::BinaryHeap<int> minHeap;
    ods::BinarySearchTree<int> bst;
    ods::Treap<int> treap(12345);

    for (int x : xs) {
        pq.insert(x);
        minHeap.add(x);
        bst.add(x);
        treap.add(x);
    }

    std::cout << "=== Evidencia observada ===\n\n";

    std::cout << "PQ_ComplHeap::getMax() = "
              << pq.getMax() << "\n";

    std::cout << "BinaryHeap::top() = "
              << minHeap.top() << "\n";

    std::cout << "BST inorder = ";
    for (int x : bst.inorder()) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << "Treap inorder = ";
    for (int x : treap.inorderKeys()) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << "\nTreap:\n";
    std::cout << treap << '\n';

    std::vector<Row> rows{
        {
            "BinaryHeap",
            "top()",
            "Min-Heap",
            "obtener minimo",
            "busqueda arbitraria",
            "top() = " + std::to_string(minHeap.top())
        },
        {
            "PQ_ComplHeap",
            "getMax()",
            "Max-Heap",
            "obtener maximo",
            "recorrido ordenado",
            "getMax() = " + std::to_string(pq.getMax())
        },
        {
            "BinarySearchTree",
            "find(x)",
            "BST",
            "buscar claves",
            "extraer maximos repetidos",
            "inorder ordenado"
        },
        {
            "Treap",
            "find(x)",
            "BST + Heap por prioridad",
            "buscar e insertar balanceado",
            "recorrido por prioridad",
            "inorder ordenado y prioridades visibles"
        }
    };

    std::cout << "\n=== Tabla comparativa ===\n\n";

    std::cout << std::left
              << std::setw(15) << "Estructura"
              << std::setw(15) << "Operacion principal"
              << std::setw(15) << "Propiedad"
              << std::setw(15) << "Operacion eficiente"
              << std::setw(15) << "No conviene"
              << "Evidencia\n";

    std::cout << std::string(150, '-') << '\n';

    for (const auto& r : rows) {
        std::cout << std::setw(15) << r.estructura
                  << std::setw(15) << r.operacionPrincipal
                  << std::setw(15) << r.propiedad
                  << std::setw(15) << r.eficiente
                  << std::setw(15) << r.noConviene
                  << r.evidencia
                  << '\n';
    }

    return 0;
}
