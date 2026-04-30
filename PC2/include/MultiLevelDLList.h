#pragma once
#include "DLList.h"
#include <iostream>
#include <string>
#include <unordered_map>

const int mMax = 1000;

namespace ods {

template <class T> class MultiLevelDLList : public DLList<T> {
protected:
  int m;
  using Node = typename DLList<T>::Node;

  std::unordered_map<Node *, MultiLevelDLList<T> *> children;
  MultiLevelDLList<T> *parent = nullptr;

  MultiLevelDLList<T> *getChild(Node *u) const {
    auto it = children.find(u);
    return (it != children.end()) ? it->second : nullptr;
  }

public:
  MultiLevelDLList() : DLList<T>(), m(0) {}

  void incrementUp(int k = 1) {
    MultiLevelDLList<T> *p = this;
    while (p != nullptr) {
      p->m += k;
      p = p->parent;
    }
  }

  void decrementUp(int k) {
    MultiLevelDLList<T> *p = this;
    while (p != nullptr) {
      p->m -= k;
      p = p->parent;
    }
  }
  void add(int i, const T &x) {
    assert(0 <= i && i <= mMax);
    DLList<T>::add(i, x);
    incrementUp(1);
  }

  void add(const T &x) {
    DLList<T>::add(this->n, x);
    incrementUp(1);
  }

  MultiLevelDLList<T> *addChild(int i) {
    Node *u = this->getNode(i);

    if (getChild(u) != nullptr) {
      return nullptr;
    }

    auto *child = new MultiLevelDLList<T>();
    child->parent = this;
    children[u] = child;

    return child;
  }

  bool hasChild(int i) { return getChild(this->getNode(i)) != nullptr; }

  void removeNode(Node *w) {
    int removed = 1;

    MultiLevelDLList<T> *child = getChild(w);
    if (child != nullptr) {
      removed += child->m; // todo el subárbol
      delete child;
      children.erase(w);
    }

    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    this->n--;

    decrementUp(removed);
  }
  T remove(int i) {
    Node *w = this->getNode(i);
    T x = w->x;
    removeNode(w);
    return x;
  }
  int size() const { return m; }

  bool checkSize() const {
    int total = 0;

    struct StackNode {
      const MultiLevelDLList<T> *list;
      StackNode *next;
    };

    StackNode *stack = new StackNode{this, nullptr};

    while (stack != nullptr) {
      const MultiLevelDLList<T> *list = stack->list;
      StackNode *tmp = stack;
      stack = stack->next;
      delete tmp;

      total += list->n;

      Node *u = list->dummy.next;
      while (u != &list->dummy) {

        auto it = list->children.find(u);
        if (it != list->children.end()) {
          stack = new StackNode{it->second, stack};
        }

        u = u->next;
      }
    }

    return total == m;
  }
  void clear() {
    // borrar children primero
    for (auto &p : children) {
      delete p.second;
    }
    children.clear();

    DLList<T>::clear();
    m = 0;
  }

  void flatten(std::vector<T> &result) const {
    Node *u = this->dummy.next;

    while (u != &this->dummy) {
      result.push_back(u->x);

      MultiLevelDLList<T> *child = getChild(u);
      if (child != nullptr) {
        child->flatten(result);
      }

      u = u->next;
    }
  }

  std::vector<T> flatten() const {
    std::vector<T> res;
    flatten(res);
    return res;
  }

  std::vector<std::string> parse(const std::string &s) {
    std::vector<std::string> result;
    std::string token;

    for (char c : s) {
      if (c == '[' || c == ']')
        continue;

      if (c == ',') {
        if (!token.empty()) {
          result.push_back(token);
          token.clear();
        }
      } else if (!isspace(c)) {
        token += c;
      }
    }

    if (!token.empty())
      result.push_back(token);

    return result;
  }
  MultiLevelDLList<T> &buildFromString(const std::string &input) {
    std::vector<std::string> input_parsed = parse(input);
    this->clear();
    if (input.empty())
      return *this;

    int i = 0;

    while (i < input_parsed.size() && input_parsed[i] != "null") {
      this->add(std::stoi(input_parsed[i]));
      i++;
    }

    i++;

    std::vector<std::pair<MultiLevelDLList<T> *, int>> stack;

    for (int j = this->size() - 1; j >= 0; --j) {
      stack.push_back({this, j});
    }

    while (!stack.empty() && i < input_parsed.size()) {

      auto [list, idx] = stack.back();
      stack.pop_back();

      if (i >= input_parsed.size())
        break;

      if (input_parsed[i] == "null") {
        i++;
        continue;
      }

      auto *child = list->addChild(idx);

      std::vector<int> values;

      while (i < input_parsed.size() && input_parsed[i] != "null") {
        values.push_back(std::stoi(input_parsed[i]));
        i++;
      }

      for (int v : values) {
        child->add(v);
      }

      for (int j = child->size() - 1; j >= 0; --j) {
        stack.push_back({child, j});
      }

      if (i < input_parsed.size())
        i++;
    }

    return *this;
  }

  ~MultiLevelDLList() {
    for (auto &p : children) {
      delete p.second;
    }
  }
};

} // namespace ods
