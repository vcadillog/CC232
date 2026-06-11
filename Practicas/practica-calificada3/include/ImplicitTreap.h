#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace ods {

template <class T> class ImplicitTreap {
protected:
  struct Node {
    T value;

    uint64_t priority;

    int _size;

    Node *left;
    Node *right;
    Node *parent;

    Node(const T &value, uint64_t priority);
  };

  Node *root_;

  std::mt19937_64 rng_;

protected:
  static int size(Node *u);

  static void update(Node *u);

  static void updateUp(Node *u);

  void rotateLeft(Node *u);

  void rotateRight(Node *u);

  void bubbleUp(Node *u);

  void trickleDown(Node *u);

  void splice(Node *u);

  Node *getNodeAt(int pos) const;

  static void inorder(Node *u, std::vector<T> &out);

  static void destroy(Node *u);

  static std::string nodeLabel(const Node *node, int index);

  static void buildAscii(const Node *node, const std::string &prefix,
                         bool isTail, int offset,
                         std::vector<std::string> &lines);

public:
  explicit ImplicitTreap(uint64_t seed = 232);

  virtual ~ImplicitTreap();

  int size() const;

  bool empty() const;

  void clear();

  void pushBack(const T &value);

  void insertAt(int pos, const T &value);

  void eraseAt(int pos);

  T getAt(int pos) const;

  void setAt(int pos, const T &value);

  std::vector<T> toVector() const;

  std::string asciiArt() const;
};

template <class T>
std::ostream &operator<<(std::ostream &out, const ImplicitTreap<T> &t);

} // namespace ods
