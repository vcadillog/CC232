#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

#include "Capitulo5.h"
#include "Capitulo6.h"

static void testBloque10TreapCompleto() {
  // MOD-A6-B10: treap vacio.
  ods::Treap<int> empty;
  assert(empty.empty());
  assert(empty.size() == 0);
  assert(empty.isBST());
  assert(empty.isHeapByPriority());
  assert(empty.isTreap());
  assert(empty.hasValidParentLinks());

  // MOD-A6-B10: insercion con prioridades fijas.
  ods::Treap<int> t(232);

  assert(t.addWithPriority(50, 50));
  assert(t.addWithPriority(30, 30));
  assert(t.addWithPriority(70, 70));
  assert(t.addWithPriority(20, 20));
  assert(t.addWithPriority(40, 40));
  assert(t.addWithPriority(60, 60));
  assert(t.addWithPriority(80, 80));

  assert(t.size() == 7);
  assert(t.root() != nullptr);
  assert(t.root()->key == 20);
  assert(t.isBST());
  assert(t.isHeapByPriority());
  assert(t.isTreap());
  assert(t.hasValidParentLinks());

  // MOD-A6-B10: rechazo de duplicados.
  assert(!t.addWithPriority(40, 5));
  assert(t.size() == 7);
  assert(t.isTreap());

  // MOD-A6-B10: inorden ordenado.
  assert((t.inorderKeys() == std::vector<int>{20, 30, 40, 50, 60, 70, 80}));

  // MOD-A6-B10: lowerBound y upperBound.
  assert(t.findEQ(40) != nullptr);
  assert(t.findEQ(35) == nullptr);

  assert(t.lowerBound(35) != nullptr);
  assert(t.lowerBound(35)->key == 40);

  assert(t.lowerBound(40) != nullptr);
  assert(t.lowerBound(40)->key == 40);

  assert(t.upperBound(40) != nullptr);
  assert(t.upperBound(40)->key == 50);

  assert(t.upperBound(75) != nullptr);
  assert(t.upperBound(75)->key == 80);

  assert(t.upperBound(80) == nullptr);

  // MOD-A6-B10: eliminacion de hoja.
  assert(t.remove(80));
  assert(t.size() == 6);
  assert(t.isTreap());
  assert(t.hasValidParentLinks());
  assert((t.inorderKeys() == std::vector<int>{20, 30, 40, 50, 60, 70}));

  // MOD-A6-B10: eliminacion de nodo con un hijo.
  assert(t.remove(70));
  assert(t.size() == 5);
  assert(t.isTreap());
  assert(t.hasValidParentLinks());
  assert((t.inorderKeys() == std::vector<int>{20, 30, 40, 50, 60}));

  // MOD-A6-B10: reconstruccion para eliminar nodo con dos hijos.
  ods::Treap<int> twoChildren(232);
  assert(twoChildren.addWithPriority(50, 50));
  assert(twoChildren.addWithPriority(30, 30));
  assert(twoChildren.addWithPriority(70, 70));
  assert(twoChildren.addWithPriority(20, 20));
  assert(twoChildren.addWithPriority(40, 40));
  assert(twoChildren.addWithPriority(60, 60));
  assert(twoChildren.addWithPriority(80, 80));

  assert(twoChildren.remove(30));
  assert(twoChildren.size() == 6);
  assert(twoChildren.isTreap());
  assert(twoChildren.hasValidParentLinks());
  assert(
      (twoChildren.inorderKeys() == std::vector<int>{20, 40, 50, 60, 70, 80}));

  // MOD-A6-B10: eliminacion de raiz.
  assert(twoChildren.root() != nullptr);
  const int oldRoot = twoChildren.root()->key;
  assert(twoChildren.remove(oldRoot));
  assert(twoChildren.size() == 5);
  assert(twoChildren.isTreap());
  assert(twoChildren.hasValidParentLinks());

  // MOD-A6-B10: operaciones mixtas e invariantes.
  ods::Treap<int> mixed(232);

  for (const auto &item :
       std::vector<std::pair<int, std::uint64_t>>{{100, 100},
                                                  {50, 50},
                                                  {150, 150},
                                                  {25, 25},
                                                  {75, 75},
                                                  {125, 125},
                                                  {175, 175},
                                                  {60, 60},
                                                  {90, 90}}) {
    assert(mixed.addWithPriority(item.first, item.second));
    assert(mixed.isTreap());
    assert(mixed.hasValidParentLinks());
  }

  assert(mixed.size() == 9);

  for (int x : {75, 25, 150, 100}) {
    assert(mixed.remove(x));
    assert(mixed.isTreap());
    assert(mixed.hasValidParentLinks());
  }

  assert(mixed.size() == 5);
  assert((mixed.inorderKeys() == std::vector<int>{50, 60, 90, 125, 175}));
}

int main() {
  // PQ_ComplHeap: secuencia completa de extracciones.
  ods::PQ_ComplHeap<int> pq;
  for (int x : {8, 3, 10, 1, 6, 14, 4, 7, 13, 14}) {
    pq.insert(x);
    assert(pq.isHeap());
  }
  std::vector<int> out;
  while (!pq.empty()) {
    out.push_back(pq.delMax());
    assert(pq.empty() || pq.isHeap());
  }
  assert((out == std::vector<int>{14, 14, 13, 10, 8, 7, 6, 4, 3, 1}));

  // Leftist heap: merge e invariantes.
  ods::PQ_LeftHeap<int> a{20, 7, 18, 3};
  ods::PQ_LeftHeap<int> b{19, 8, 4, 1, 17};
  a.merge(b);
  assert(a.isLeftistHeap());
  assert(b.empty());
  std::vector<int> leftOut;
  while (!a.empty()) {
    leftOut.push_back(a.delMax());
    assert(a.empty() || a.isLeftistHeap());
  }
  assert((leftOut == std::vector<int>{20, 19, 18, 17, 8, 7, 4, 3, 1}));

  // Huffman con heap completo y leftist heap deben tener mismo costo ponderado.
  const std::vector<ods::HuffmanSymbol> s{{'a', 45}, {'b', 13}, {'c', 12},
                                          {'d', 16}, {'e', 9},  {'f', 5}};
  const auto codes1 = ods::huffmanGenerateCodes(s);
  const auto codes2 = ods::huffmanGenerateCodesLeftHeap(s);
  assert(ods::huffmanIsPrefixFree(codes1));
  assert(ods::huffmanIsPrefixFree(codes2));
  assert(ods::huffmanWeightedPathLength(s, codes1) == 224);
  assert(ods::huffmanWeightedPathLength(s, codes2) == 224);

  // Rotaciones BST: preservan inorder aun cuando cambie la forma.
  ods::BinarySearchTree<int> bst;
  for (int x : {8, 3, 10, 1, 6, 14, 4, 7, 13}) {
    bst.add(x);
  }
  auto sorted = bst.inorder();
  bst.rotateLeft(bst.root());
  assert(bst.isBST());
  assert(bst.inorder() == sorted);
  bst.rotateRight(bst.root());
  assert(bst.isBST());
  assert(bst.inorder() == sorted);

  // Treap: BST por clave + heap por prioridad.
  ods::Treap<int> treap(555);
  treap.addWithPriority(8, 80);
  treap.addWithPriority(3, 40);
  treap.addWithPriority(10, 90);
  treap.addWithPriority(1, 20);
  treap.addWithPriority(6, 70);
  treap.addWithPriority(14, 120);
  treap.addWithPriority(4, 65);
  treap.addWithPriority(7, 68);
  assert(treap.isTreap());
  assert((treap.inorderKeys() == std::vector<int>{1, 3, 4, 6, 7, 8, 10, 14}));
  assert(treap.lowerBound(5)->key == 6);
  assert(treap.upperBound(6)->key == 7);
  assert(treap.remove(3));
  assert(treap.remove(8));
  assert(treap.isTreap());
  assert((treap.inorderKeys() == std::vector<int>{1, 4, 6, 7, 10, 14}));

  testBloque10TreapCompleto();
}
