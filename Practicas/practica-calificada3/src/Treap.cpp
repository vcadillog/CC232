#include "Treap.h"
#include <cassert>

namespace ods {

template <class T, class Compare>
Treap<T, Compare>::Node::Node(const T &value, std::uint64_t p, Node *par)
    : key(value), priority(p), parent(par) {}

template <class T, class Compare>
bool Treap<T, Compare>::Node::isLeftChild() const {
  return parent != nullptr && parent->left == this;
}

template <class T, class Compare>
bool Treap<T, Compare>::Node::isRightChild() const {
  return parent != nullptr && parent->right == this;
}

template <class T, class Compare>
Treap<T, Compare>::Treap() : rng_(232) {}

template <class T, class Compare>
Treap<T, Compare>::Treap(std::uint64_t seed) : rng_(seed) {}

template <class T, class Compare>
Treap<T, Compare>::Treap(Compare comp, std::uint64_t seed)
    : comp_(std::move(comp)), rng_(seed) {}

template <class T, class Compare>
Treap<T, Compare>::Treap(Treap &&other) noexcept {
  swap(other);
}

template <class T, class Compare>
Treap<T, Compare> &Treap<T, Compare>::operator=(Treap &&other) noexcept {
  if (this != &other) {
    clear();
    swap(other);
  }
  return *this;
}

template <class T, class Compare>
Treap<T, Compare>::~Treap() {
  clear();
}

template <class T, class Compare>
void Treap<T, Compare>::clear() {
  destroy(root_);
  root_ = nullptr;
  size_ = 0;
}

template <class T, class Compare>
void Treap<T, Compare>::swap(Treap &other) noexcept {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
  std::swap(comp_, other.comp_);
  std::swap(rng_, other.rng_);
  std::swap(priorityCounter_, other.priorityCounter_);
}

template <class T, class Compare>
typename Treap<T, Compare>::Node *Treap<T, Compare>::root() const noexcept {
  return root_;
}

template <class T, class Compare>
std::size_t Treap<T, Compare>::size() const noexcept {
  return size_;
}

template <class T, class Compare>
bool Treap<T, Compare>::empty() const noexcept {
  return size_ == 0;
}

template <class T, class Compare>
typename Treap<T, Compare>::Node *Treap<T, Compare>::findLast(const T &x) const {
  Node *w = root_;
  Node *prev = nullptr;
  while (w != nullptr) {
    prev = w;
    if (comp_(x, w->key)) {
      w = w->left;
    } else if (comp_(w->key, x)) {
      w = w->right;
    } else {
      return w;
    }
  }
  return prev;
}

template <class T, class Compare>
typename Treap<T, Compare>::Node *Treap<T, Compare>::findEQ(const T &x) const {
  Node *w = root_;
  while (w != nullptr) {
    if (comp_(x, w->key)) {
      w = w->left;
    } else if (comp_(w->key, x)) {
      w = w->right;
    } else {
      return w;
    }
  }
  return nullptr;
}

template <class T, class Compare>
typename Treap<T, Compare>::Node *Treap<T, Compare>::lowerBound(const T &x) const {
  Node *w = root_;
  Node *candidate = nullptr;
  while (w != nullptr) {
    if (comp_(x, w->key)) {
      candidate = w;
      w = w->left;
    } else if (comp_(w->key, x)) {
      w = w->right;
    } else {
      return w;
    }
  }
  return candidate;
}

template <class T, class Compare>
typename Treap<T, Compare>::Node *Treap<T, Compare>::upperBound(const T &x) const {
  Node *w = root_;
  Node *candidate = nullptr;
  while (w != nullptr) {
    if (comp_(x, w->key)) {
      candidate = w;
      w = w->left;
    } else {
      w = w->right;
    }
  }
  return candidate;
}

template <class T, class Compare>
bool Treap<T, Compare>::contains(const T &x) const {
  return findEQ(x) != nullptr;
}

template <class T, class Compare>
bool Treap<T, Compare>::add(const T &x) {
  return addWithPriority(x, nextPriority());
}

template <class T, class Compare>
bool Treap<T, Compare>::addWithPriority(const T &x, std::uint64_t priority) {
  Node *u = new Node(x, priority);
  if (!addNode(u)) {
    delete u;
    return false;
  }
  bubbleUp(u);
  return true;
}

template <class T, class Compare>
bool Treap<T, Compare>::remove(const T &x) {
  Node *u = findEQ(x);
  if (!u)
    return false;
  trickleDown(u);
  splice(u);
  delete u;
  return true;
}

template <class T, class Compare>
void Treap<T, Compare>::rotateLeft(Node *u) {
  if (!u || !u->right)
    return;
  Node *w = u->right;
  w->parent = u->parent;
  if (!u->parent) {
    root_ = w;
  } else if (u->isLeftChild()) {
    u->parent->left = w;
  } else {
    u->parent->right = w;
  }
  u->right = w->left;
  if (u->right)
    u->right->parent = u;
  w->left = u;
  u->parent = w;
}

template <class T, class Compare>
void Treap<T, Compare>::rotateRight(Node *u) {
  if (!u || !u->left)
    return;
  Node *w = u->left;
  w->parent = u->parent;
  if (!u->parent) {
    root_ = w;
  } else if (u->isLeftChild()) {
    u->parent->left = w;
  } else {
    u->parent->right = w;
  }
  u->left = w->right;
  if (u->left)
    u->left->parent = u;
  w->right = u;
  u->parent = w;
}

template <class T, class Compare>
void Treap<T, Compare>::bubbleUp(Node *u) {
  static_cast<void>(bubbleUpCount(u));
}

template <class T, class Compare>
std::size_t Treap<T, Compare>::bubbleUpCount(Node *u) {
  std::size_t rotations = 0;
  while (u->parent && u->parent->priority > u->priority) {
    if (u->isRightChild()) {
      rotateLeft(u->parent);
    } else {
      rotateRight(u->parent);
    }
    ++rotations;
  }
  if (!u->parent) {
    root_ = u;
  }
  return rotations;
}

template <class T, class Compare>
std::size_t Treap<T, Compare>::trickleDownCount(Node *u) {
  std::size_t rotations = 0;
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
    ++rotations;
    if (root_ == u) {
      root_ = u->parent;
    }
  }
  return rotations;
}

template <class T, class Compare>
void Treap<T, Compare>::trickleDown(Node *u) {
  static_cast<void>(trickleDownCount(u));
}

template <class T, class Compare>
std::vector<T> Treap<T, Compare>::inorderKeys() const {
  std::vector<T> out;
  inorder(root_, out);
  return out;
}

template <class T, class Compare>
std::vector<T> Treap<T, Compare>::levelOrderKeys() const {
  std::vector<T> out;
  std::queue<Node *> q;
  if (root_)
    q.push(root_);
  while (!q.empty()) {
    Node *u = q.front();
    q.pop();
    out.push_back(u->key);
    if (u->left)
      q.push(u->left);
    if (u->right)
      q.push(u->right);
  }
  return out;
}

template <class T, class Compare>
std::string Treap<T, Compare>::asciiArt() const {
  if (!root_)
    return "(treap vacio)\n";
  std::vector<std::string> lines;
  buildAscii(root_, "", true, lines);
  std::ostringstream out;
  for (const auto &line : lines)
    out << line << '\n';
  return out.str();
}

template <class T, class Compare>
bool Treap<T, Compare>::isBST() const {
  return isBST(root_, nullptr, nullptr) && checkParents(root_, nullptr);
}

template <class T, class Compare>
bool Treap<T, Compare>::isHeapByPriority() const {
  return isHeapByPriority(root_);
}

template <class T, class Compare>
bool Treap<T, Compare>::isTreap() const {
  return isBST() && isHeapByPriority();
}

template <class T, class Compare>
std::size_t Treap<T, Compare>::addWithPriorityCount(const T &x, std::uint64_t priority) {
  Node *u = new Node(x, priority);
  if (!addNode(u)) {
    delete u;
    return 0;
  }
  return bubbleUpCount(u);
}

template <class T, class Compare>
std::size_t Treap<T, Compare>::removeCount(const T &x) {
  Node *u = findEQ(x);
  if (!u) {
    return 0;
  }
  const std::size_t rotations = trickleDownCount(u);
  splice(u);
  delete u;
  return rotations;
}

template <class T, class Compare>
bool Treap<T, Compare>::hasValidParentLinks() const {
  return checkParents(root_, nullptr);
}

template <class T, class Compare>
std::uint64_t Treap<T, Compare>::nextPriority() {
  std::uint64_t raw = rng_();
  return (raw << 16) ^ (++priorityCounter_);
}

template <class T, class Compare>
bool Treap<T, Compare>::addNode(Node *u) {
  u->left = nullptr;
  u->right = nullptr;
  Node *p = findLast(u->key);
  if (!p) {
    root_ = u;
    u->parent = nullptr;
    ++size_;
    return true;
  }
  if (comp_(u->key, p->key)) {
    if (p->left)
      return false;
    p->left = u;
  } else if (comp_(p->key, u->key)) {
    if (p->right)
      return false;
    p->right = u;
  } else {
    return false;
  }
  u->parent = p;
  ++size_;
  return true;
}

template <class T, class Compare>
void Treap<T, Compare>::splice(Node *u) {
  Node *s = u->left ? u->left : u->right;
  if (u == root_) {
    root_ = s;
  } else if (u->isLeftChild()) {
    u->parent->left = s;
  } else {
    u->parent->right = s;
  }
  if (s)
    s->parent = u->parent;
  --size_;
}

template <class T, class Compare>
void Treap<T, Compare>::destroy(Node *u) {
  if (!u)
    return;
  destroy(u->left);
  destroy(u->right);
  delete u;
}

template <class T, class Compare>
void Treap<T, Compare>::inorder(Node *u, std::vector<T> &out) {
  if (!u)
    return;
  inorder(u->left, out);
  out.push_back(u->key);
  inorder(u->right, out);
}

template <class T, class Compare>
bool Treap<T, Compare>::isBST(Node *u, const T *low, const T *high) const {
  if (!u)
    return true;
  if (low && !comp_(*low, u->key))
    return false;
  if (high && !comp_(u->key, *high))
    return false;
  return isBST(u->left, low, &u->key) && isBST(u->right, &u->key, high);
}

template <class T, class Compare>
bool Treap<T, Compare>::checkParents(Node *u, Node *parent) {
  if (!u)
    return true;
  if (u->parent != parent)
    return false;
  return checkParents(u->left, u) && checkParents(u->right, u);
}

template <class T, class Compare>
bool Treap<T, Compare>::isHeapByPriority(Node *u) {
  if (!u)
    return true;
  if (u->left && u->left->priority < u->priority)
    return false;
  if (u->right && u->right->priority < u->priority)
    return false;
  return isHeapByPriority(u->left) && isHeapByPriority(u->right);
}

template <class T, class Compare>
std::string Treap<T, Compare>::nodeLabel(const Node *u) {
  std::ostringstream out;
  out << u->key << "|p=" << u->priority;
  return out.str();
}

template <class T, class Compare>
void Treap<T, Compare>::buildAscii(const Node *node, const std::string &prefix,
                                   bool isTail, std::vector<std::string> &lines) {
  if (!node)
    return;
  if (node->right) {
    buildAscii(node->right, prefix + (isTail ? "│   " : "    "), false, lines);
  }
  lines.push_back(prefix + (isTail ? "└── " : "┌── ") + nodeLabel(node));
  if (node->left) {
    buildAscii(node->left, prefix + (isTail ? "    " : "│   "), true, lines);
  }
}

template <class T, class Compare>
std::ostream &operator<<(std::ostream &out, const Treap<T, Compare> &t) {
  out << t.asciiArt();
  return out;
}

template class Treap<int>;
template class Treap<double>;
template class Treap<std::string>;

template std::ostream& operator<<(std::ostream&, const Treap<int>&);
template std::ostream& operator<<(std::ostream&, const Treap<double>&);
template std::ostream& operator<<(std::ostream&, const Treap<std::string>&);

} // namespace ods
