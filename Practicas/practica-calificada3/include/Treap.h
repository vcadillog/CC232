#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <ostream>
#include <queue>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace ods {

template <class T, class Compare = std::less<T>> class Treap {
public:
  struct Node {
    T key{};
    std::uint64_t priority{0};
    Node *parent{nullptr};
    Node *left{nullptr};
    Node *right{nullptr};

    Node() = default;
    Node(const T &value, std::uint64_t p, Node *par = nullptr);

    bool isLeftChild() const;
    bool isRightChild() const;
  };

  Treap();
  explicit Treap(std::uint64_t seed);
  explicit Treap(Compare comp, std::uint64_t seed = 232);

  Treap(const Treap &) = delete;
  Treap &operator=(const Treap &) = delete;

  Treap(Treap &&other) noexcept;
  Treap &operator=(Treap &&other) noexcept;

  ~Treap();

  void clear();
  void swap(Treap &other) noexcept;

  Node *root() const noexcept;
  std::size_t size() const noexcept;
  bool empty() const noexcept;

  Node *findLast(const T &x) const;
  Node *findEQ(const T &x) const;
  Node *lowerBound(const T &x) const;
  Node *upperBound(const T &x) const;
  bool contains(const T &x) const;

  bool add(const T &x);
  bool addWithPriority(const T &x, std::uint64_t priority);
  bool remove(const T &x);

  void rotateLeft(Node *u);
  void rotateRight(Node *u);
  void bubbleUp(Node *u);
  std::size_t bubbleUpCount(Node *u);
  std::size_t trickleDownCount(Node *u);
  void trickleDown(Node *u);

  std::vector<T> inorderKeys() const;
  std::vector<T> levelOrderKeys() const;
  std::string asciiArt() const;

  bool isBST() const;
  bool isHeapByPriority() const;
  bool isTreap() const;

  std::size_t addWithPriorityCount(const T &x, std::uint64_t priority);
  std::size_t removeCount(const T &x);
  bool hasValidParentLinks() const;

private:
  Node *root_{nullptr};
  std::size_t size_{0};
  Compare comp_{};
  std::mt19937_64 rng_;
  std::uint64_t priorityCounter_{0};

  std::uint64_t nextPriority();
  bool addNode(Node *u);
  void splice(Node *u);

  static void destroy(Node *u);
  static void inorder(Node *u, std::vector<T> &out);
  bool isBST(Node *u, const T *low, const T *high) const;
  static bool checkParents(Node *u, Node *parent);
  static bool isHeapByPriority(Node *u);
  static std::string nodeLabel(const Node *u);
  static void buildAscii(const Node *node, const std::string &prefix,
                         bool isTail, std::vector<std::string> &lines);
};

template <class T, class Compare>
std::ostream &operator<<(std::ostream &out, const Treap<T, Compare> &t);

} // namespace ods
