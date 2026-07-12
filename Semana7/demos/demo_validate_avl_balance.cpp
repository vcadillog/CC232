#include "Capitulo7.h"
#include <cstdlib>
#include <iostream>

template <typename Node> int computeHeight(Node *node) {
  if (node == nullptr)
    return -1;
  int lh = computeHeight(node->lc);
  int rh = computeHeight(node->rc);
  return 1 + std::max(lh, rh);
}

template <typename Node> bool validateAVLBalance(Node *node) {
  if (node == nullptr)
    return true;
  int lh = computeHeight(node->lc);
  int rh = computeHeight(node->rc);
  if (std::abs(lh - rh) > 1)
    return false;
  return validateAVLBalance(node->lc) && validateAVLBalance(node->rc);
}

int main() {
  ods::AVL<int> avl;
  std::cout << "Altura árbol vacío: " << computeHeight(avl.root()) << std::endl;

  for (int x : {30, 20, 10, 25, 40, 50, 22, 27}) {
    avl.insert(x);
  }
// AVL
//       30
//      /  \                                                                                    
//    20    40
//   /  \     \                                                                                 
// 10   25     50
//      / \                                                                                     
//    22  27
//

  std::cout << "Validacion AVL despues de inserciones\n";

  auto root = avl.root();
  int h = computeHeight(root);
  bool balanced = validateAVLBalance(root);

  std::cout << "Estado: " << (balanced ? "balanceado" : "no balanceado")
            << "\n";
  std::cout << "Altura calculada: " << h << "\n";

  auto &pos = avl.search(10);
  h = computeHeight(pos);
  std::cout << "Altura de hoja 10: " << h << std::endl;
  return 0;
}
