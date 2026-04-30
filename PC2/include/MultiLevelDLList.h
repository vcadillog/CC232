#pragma once
#include "DLList.h"
#include <string>
#include <unordered_map>

namespace ods {

template <class T> class MultiLevelDLList : public DLList<T> {
protected:
  using Node = typename DLList<T>::Node;

  std::unordered_map<Node *, MultiLevelDLList<T> *> children;

  MultiLevelDLList<T> *getChild(Node *u) const {
    auto it = children.find(u);
    return (it != children.end()) ? it->second : nullptr;
  }

public:
  MultiLevelDLList() : DLList<T>() {}

  MultiLevelDLList<T> *addChild(int i) {
    Node *u = this->getNode(i);

    if (getChild(u) != nullptr) {
      return nullptr;
    }

    auto *child = new MultiLevelDLList<T>();
    children[u] = child;

    return child;
  }

  bool hasChild(int i) { return getChild(this->getNode(i)) != nullptr; }

  void removeNode(Node *w) {
    MultiLevelDLList<T> *child = getChild(w);

    if (child != nullptr) {
      delete child;
      children.erase(w);
    }

    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    this->n--;
  }

  T remove(int i) {
    Node *w = this->getNode(i);
    T x = w->x;
    removeNode(w);
    return x;
  }

  int sizeDeep() const {
    int total = 0;

    Node *u = this->dummy.next;
    while (u != &this->dummy) {
      total++;

      MultiLevelDLList<T> *child = getChild(u);
      if (child != nullptr) {
        total += child->sizeDeep();
      }

      u = u->next;
    }

    return total;
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
