#include <cassert>
#include <vector>
#include "Capitulo7.h"

int main() {
    {
        ods::AVL<int> avl;
        for (int x : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) avl.insert(x);
        assert((avl.inorder() == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
        assert(avl.isAVLValid());
        assert(avl.height() <= 4);
    }
    {
        ods::RedBlackTreeLLRB<int> rb;
        for (int x : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) rb.add(x);
        assert((rb.inorder() == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
        assert(rb.isRedBlackTree());
    }
    {
        ods::RedBlackTreeLLRB<int> rb;
        for (int x : {40, 20, 60, 10, 30, 50, 70, 5, 15, 25, 35}) rb.add(x);
        assert(rb.contains(40));
        assert(rb.contains(5));
        assert(rb.contains(70));
        assert(!rb.contains(99));
        assert(rb.isRedBlackTree());
    }
    return 0;
}
