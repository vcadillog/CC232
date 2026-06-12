#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

#include "Capitulo5.h"
#include "Capitulo6.h"

static void testBloque5ValidacionHeapPublica() {
  // MOD-A6-B5: caso 1 - heap vacio.
  ods::PQ_ComplHeap<int> emptyHeap;
  assert(emptyHeap.empty());
  assert(emptyHeap.isValidHeap());
  assert(emptyHeap.isHeap());

  // MOD-A6-B5: caso 2 - heap con un elemento.
  ods::PQ_ComplHeap<int> oneElementHeap;
  oneElementHeap.insert(42);
  assert(oneElementHeap.size() == 1);
  assert(oneElementHeap.getMax() == 42);
  assert(oneElementHeap.isValidHeap());

  // MOD-A6-B5: caso 3 - heap con elementos repetidos.
  ods::PQ_ComplHeap<int> repeatedHeap;
  for (int x : {5, 5, 5, 3, 3, 8, 8, 1}) {
    repeatedHeap.insert(x);
    assert(repeatedHeap.isValidHeap());
  }
  assert(repeatedHeap.getMax() == 8);

  // MOD-A6-B5: caso 4 - heap construido por inserciones.
  ods::PQ_ComplHeap<int> insertedHeap;
  for (int x : {40, 10, 70, 30, 90, 20, 80, 60}) {
    insertedHeap.insert(x);
    assert(insertedHeap.isValidHeap());
  }
  assert(insertedHeap.getMax() == 90);

  // MOD-A6-B5: caso 5 - heap construido por heapify mediante constructor.
  ods::PQ_ComplHeap<int> heapifiedHeap{4, 17, 3,  90, 55, 21,
                                       8, 13, 34, 2,  1,  89};
  assert(heapifiedHeap.isValidHeap());
  assert(heapifiedHeap.getMax() == 90);

  // MOD-A6-B5: caso 6 - heap despues de varias llamadas a delMax.
  int previous = heapifiedHeap.delMax();
  assert(previous == 90);
  assert(heapifiedHeap.isValidHeap());

  while (!heapifiedHeap.empty()) {
    const int current = heapifiedHeap.delMax();

    // En max-heap, las extracciones deben salir en orden no creciente.
    assert(previous >= current);
    previous = current;

    assert(heapifiedHeap.isValidHeap());
  }
}

int main() {
  testBloque5ValidacionHeapPublica();
  ods::PQ_ComplHeap<int> h{4, 10, 7, 1, 3, 9};
  assert(h.isHeap());
  assert(h.getMax() == 10);
  h.insert(12);
  assert(h.isHeap());
  assert(h.delMax() == 12);
  assert(h.isHeap());

  std::vector<int> xs{5, 1, 8, 3, 2};
  ods::heapSort(xs);
  assert((xs == std::vector<int>{1, 2, 3, 5, 8}));

  ods::PQ_LeftHeap<int> a{7, 2, 9};
  ods::PQ_LeftHeap<int> b{1, 8, 3};
  ods::leftHeapMerge(a, b);
  assert(b.empty());
  assert(a.size() == 6);
  assert(a.isLeftistHeap());
  assert(a.getMax() == 9);

  const std::vector<ods::HuffmanSymbol> s{{'a', 45}, {'b', 13}, {'c', 12},
                                          {'d', 16}, {'e', 9},  {'f', 5}};
  const auto codes = ods::huffmanGenerateCodes(s);
  const auto tree = ods::huffmanGenerateTree(s);
  const std::string msg = "face";
  const std::string bits = ods::huffmanEncode(msg, codes);
  assert(ods::huffmanDecode(bits, tree) == msg);
  assert(ods::huffmanIsPrefixFree(codes));

  ods::BinarySearchTree<int> bst;
  for (int x : {8, 3, 10, 1, 6, 14, 4, 7}) {
    bst.add(x);
  }
  const auto before = bst.inorder();
  bst.rotateRight(bst.root());
  bst.rotateLeft(bst.root());
  const auto after = bst.inorder();
  assert(before == after);
  assert(bst.isBST());

  ods::Treap<int> treap(123);
  assert(treap.addWithPriority(8, 80));
  assert(treap.addWithPriority(3, 60));
  assert(treap.addWithPriority(10, 90));
  assert(treap.addWithPriority(1, 50));
  assert(treap.addWithPriority(6, 70));
  assert(treap.isTreap());
  assert(!treap.addWithPriority(6, 71));
  assert(treap.contains(3));
  assert(treap.remove(3));
  assert(!treap.contains(3));
  assert(treap.isTreap());
}
