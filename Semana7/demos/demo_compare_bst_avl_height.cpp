#include "Capitulo7.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> mixedKeys = {5, 2, 8, 1, 3, 7, 9, 4, 6, 10};

  int h_bst_ord, h_avl_ord, h_bst_mix, h_avl_mix;

  {
    ods::BST<int> bst;
    for (int x : sortedKeys) bst.insert(x);
    h_bst_ord = bst.height();
  }
  {
    ods::AVL<int> avl;
    for (int x : sortedKeys) avl.insert(x);
    h_avl_ord = avl.height();
  }
  {
    ods::BST<int> bst;
    for (int x : mixedKeys) bst.insert(x);
    h_bst_mix = bst.height();
  }
  {
    ods::AVL<int> avl;
    for (int x : mixedKeys) avl.insert(x);
    h_avl_mix = avl.height();
  }

  std::cout << "Caso: claves ordenadas\n";
  std::cout << "Altura BST: " << h_bst_ord << "\n";
  std::cout << "Altura AVL: " << h_avl_ord << "\n";
  std::cout << "\nCaso: claves mezcladas\n";
  std::cout << "Altura BST: " << h_bst_mix << "\n";
  std::cout << "Altura AVL: " << h_avl_mix << "\n";

  std::cout << "\nTabla comparativa\n";
  std::cout << "Caso\t\tBST\tAVL\n";
  std::cout << "Ordenadas\t" << h_bst_ord << "\t" << h_avl_ord << "\n";
  std::cout << "Mezcladas\t" << h_bst_mix << "\t" << h_avl_mix << "\n";

  std::cout << "\nInterpretacion\n";

  std::cout
      << "1. ¿Qué ocurre con el BST cuando las claves llegan ordenadas?\n";
  std::cout << "1. BST con claves ordenadas: degenera a lista enlazada (altura "
               "O(n)).\n";
  std::cout << "2. ¿Qué ocurre con AVL ante la misma entrada?\n";
  std::cout << "2. AVL con la misma entrada: rota para mantenerse balanceado "
               "(altura O(log n)).\n";
  std::cout << "3. ¿Por qué ambas estructuras conservan el mismo inorder?\n";
  std::cout << "3. Ambas conservan el inorder identico porque la propiedad BST "
               "es invariante bajo rotaciones.\n";
  std::cout << "4. ¿Por qué la altura es la evidencia central en esta "
               "comparación?.\n";
  std::cout << "4. La altura es evidencia central porque determina el costo de "
               "busqueda: O(altura).\n";

  return 0;
}
