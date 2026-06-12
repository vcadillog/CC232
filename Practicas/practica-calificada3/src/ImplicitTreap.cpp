#include "ImplicitTreap.h"
#include <sstream>

namespace ods {

template <class T>
ImplicitTreap<T>::Node::Node(const T &value, uint64_t priority)
    : value(value), priority(priority), _size(1), left(nullptr), right(nullptr),
      parent(nullptr) {}

template <class T>
ImplicitTreap<T>::ImplicitTreap(uint64_t seed) : root_(nullptr), rng_(seed) {}

template <class T> ImplicitTreap<T>::~ImplicitTreap() { clear(); }

template <class T> int ImplicitTreap<T>::size(Node *u) {
  return u ? u->_size : 0;
}

template <class T> void ImplicitTreap<T>::update(Node *u) {
  if (!u)
    return;

  u->_size = 1 + size(u->left) + size(u->right);
}

template <class T> void ImplicitTreap<T>::updateUp(Node *u) {
  while (u) {
    update(u);
    u = u->parent;
  }
}

template <class T> void ImplicitTreap<T>::rotateLeft(Node *u) {
  Node *w = u->right;

  if (!w)
    return;

  w->parent = u->parent;

  if (!u->parent) {
    root_ = w;
  } else if (u == u->parent->left) {
    u->parent->left = w;
  } else {
    u->parent->right = w;
  }

  u->right = w->left;

  if (w->left)
    w->left->parent = u;

  w->left = u;
  u->parent = w;

  update(u);
  update(w);
}

template <class T> void ImplicitTreap<T>::rotateRight(Node *u) {
  Node *w = u->left;

  if (!w)
    return;

  w->parent = u->parent;

  if (!u->parent) {
    root_ = w;
  } else if (u == u->parent->left) {
    u->parent->left = w;
  } else {
    u->parent->right = w;
  }

  u->left = w->right;

  if (w->right)
    w->right->parent = u;

  w->right = u;
  u->parent = w;

  update(u);
  update(w);
}

template <class T> void ImplicitTreap<T>::bubbleUp(Node *u) {
  while (u->parent && u->priority < u->parent->priority) {
    if (u == u->parent->left) {
      rotateRight(u->parent);
    } else {
      rotateLeft(u->parent);
    }
  }

  if (!u->parent)
    root_ = u;
}

template <class T> void ImplicitTreap<T>::trickleDown(Node *u) {
  while (u->left || u->right) {
    if (!u->left) {
      rotateLeft(u);
    } else if (!u->right) {
      rotateRight(u);
    } else if (u->left->priority < u->right->priority) {
      rotateRight(u);
    } else {
      rotateLeft(u);
    }

    if (root_ == u)
      root_ = u->parent;
  }
}

template <class T> void ImplicitTreap<T>::splice(Node *u) {
  Node *s = u->left ? u->left : u->right;

  Node *p = u->parent;

  if (!u->parent) {
    root_ = s;
  } else if (u == u->parent->left) {
    u->parent->left = s;
  } else {
    u->parent->right = s;
  }

  if (s)
    s->parent = u->parent;

  delete u;

  updateUp(p);
}

template <class T>
typename ImplicitTreap<T>::Node *ImplicitTreap<T>::getNodeAt(int pos) const {
  if (pos < 0 || pos >= size())
    return nullptr;

  Node *u = root_;

  while (u) {
    int leftSize = size(u->left);

    if (pos < leftSize) {
      u = u->left;
    } else if (pos > leftSize) {
      pos -= leftSize + 1;
      u = u->right;
    } else {
      return u;
    }
  }

  return nullptr;
}

template <class T> int ImplicitTreap<T>::size() const { return size(root_); }

template <class T> bool ImplicitTreap<T>::empty() const {
  return root_ == nullptr;
}

template <class T> void ImplicitTreap<T>::pushBack(const T &value) {
  insertAt(size(), value);
}

template <class T> void ImplicitTreap<T>::insertAt(int pos, const T &value) {
  if (pos < 0 || pos > size())
    throw std::out_of_range("insertAt");

  Node *L = nullptr;
  Node *R = nullptr;

  split(root_, pos, L, R);

  Node *node = new Node(value, rng_());

  node->left = node->right = node->parent = nullptr;
  node->_size = 1;

  root_ = merge(merge(L, node), R);
}
template <class T> void ImplicitTreap<T>::eraseAt(int pos) {
  if (pos < 0 || pos >= size())
    throw std::out_of_range("eraseAt");

  Node *L = nullptr;
  Node *M = nullptr;
  Node *R = nullptr;

  split(root_, pos, L, R);
  split(R, 1, M, R);

  delete M;

  root_ = merge(L, R);
}

template <class T> T ImplicitTreap<T>::getAt(int pos) const {
  Node *u = getNodeAt(pos);

  if (!u) {
    throw std::out_of_range("getAt");
  }

  return u->value;
}

template <class T> void ImplicitTreap<T>::setAt(int pos, const T &value) {
  Node *u = getNodeAt(pos);

  if (!u) {
    throw std::out_of_range("setAt");
  }

  u->value = value;
}

template <class T>
void ImplicitTreap<T>::inorder(Node *u, std::vector<T> &out) {
  if (!u)
    return;

  inorder(u->left, out);

  out.push_back(u->value);

  inorder(u->right, out);
}

template <class T> std::vector<T> ImplicitTreap<T>::toVector() const {
  std::vector<T> out;

  inorder(root_, out);

  return out;
}

template <class T> void ImplicitTreap<T>::destroy(Node *u) {
  if (!u)
    return;

  destroy(u->left);
  destroy(u->right);

  delete u;
}

template <class T> void ImplicitTreap<T>::clear() {
  destroy(root_);

  root_ = nullptr;
}

template <class T>
std::string ImplicitTreap<T>::nodeLabel(const Node *node, int index) {
  std::ostringstream oss;

  oss << node->value << " [idx=" << index << ", sz=" << node->_size << "]";

  return oss.str();
}

template <class T>
void ImplicitTreap<T>::buildAscii(const Node *node, const std::string &prefix,
                                  bool isTail, int offset,
                                  std::vector<std::string> &lines) {
  if (!node)
    return;

  int leftSize = size(node->left);

  int index = offset + leftSize;

  if (node->right) {
    buildAscii(node->right, prefix + (isTail ? "│   " : "    "), false,
               index + 1, lines);
  }

  std::ostringstream oss;

  oss << prefix << (isTail ? "└── " : "┌── ") << node->value
      << " [idx=" << index << ", sz=" << node->_size << "]";

  lines.push_back(oss.str());

  if (node->left) {
    buildAscii(node->left, prefix + (isTail ? "    " : "│   "), true, offset,
               lines);
  }
}
template <class T> std::string ImplicitTreap<T>::asciiArt() const {
  if (!root_)
    return "(empty)\n";

  std::vector<std::string> lines;

  buildAscii(root_, "", true, 0, lines);

  std::ostringstream oss;

  for (auto &s : lines) {
    oss << s << '\n';
  }

  return oss.str();
}
template <class T>
void ImplicitTreap<T>::split(Node *t, int k, Node *&l, Node *&r) {
  if (!t) {
    l = r = nullptr;
    return;
  }

  int leftSize = size(t->left);

  if (k <= leftSize) {
    split(t->left, k, l, t->left);
    if (t->left)
      t->left->parent = t;
    r = t;
  } else {
    split(t->right, k - leftSize - 1, t->right, r);
    if (t->right)
      t->right->parent = t;
    l = t;
  }

  update(t);
}

template <class T>
typename ImplicitTreap<T>::Node *
ImplicitTreap<T>::merge(typename ImplicitTreap<T>::Node *l,
                        typename ImplicitTreap<T>::Node *r) {

  if (!l || !r)
    return l ? l : r;

  if (l->priority < r->priority) {
    l->right = merge(l->right, r);
    if (l->right)
      l->right->parent = l;
    update(l);
    return l;
  } else {
    r->left = merge(l, r->left);
    if (r->left)
      r->left->parent = r;
    update(r);
    return r;
  }
}

template <class T>
std::ostream &operator<<(std::ostream &out, const ImplicitTreap<T> &t) {
  out << t.asciiArt();

  return out;
}

template class ImplicitTreap<int>;

template std::ostream &operator<<(std::ostream &, const ImplicitTreap<int> &);

} // namespace ods
