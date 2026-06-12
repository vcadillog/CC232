#pragma once

#include <functional>
#include <initializer_list>
#include <stdexcept>
#include <utility>
#include <vector>

#include "PQ.h"
#include "PQ_ComplHeap_delMax.h"
#include "PQ_ComplHeap_getMax.h"
#include "PQ_ComplHeap_heapifyFloyd.h"
#include "PQ_ComplHeap_insert.h"
#include "PQ_ComplHeap_macro.h"
#include "PQ_ComplHeap_validate.h"

namespace ods {

template <class T, class Compare = std::less<T>>
class PQ_ComplHeap : public PQ<T> {
public:
  PQ_ComplHeap() = default;
  explicit PQ_ComplHeap(Compare comp) : comp_(std::move(comp)) {}

  explicit PQ_ComplHeap(std::vector<T> values, Compare comp = Compare{})
      : data_(std::move(values)), comp_(std::move(comp)) {
    heapify();
  }

  PQ_ComplHeap(std::initializer_list<T> values, Compare comp = Compare{})
      : data_(values), comp_(std::move(comp)) {
    heapify();
  }

  void insert(const T &e) override { complHeapInsert(data_, e, comp_); }
  void insertMerge(const T &e) override { complHeapInsert(data_, e, comp_); }
  std::size_t insertComentado(const T &e) override {
    return complHeapInsertComentado(data_, e, comp_);
  }

  template <class InputIt> void insertAll(InputIt first, InputIt last) {
    for (; first != last; ++first) {
      insert(*first);
    }
  }

  T delMax() override { return complHeapDelMax(data_, comp_); }
  T delMaxLeftist() override { return complHeapDelMax(data_, comp_); }
  HeapResult<T> delMaxComentado() override {
    return complHeapDelMaxComentado(data_, comp_);
  }

  const T &getMax() const override { return complHeapGetMax(data_); }
  bool empty() const noexcept override { return data_.empty(); }
  std::size_t size() const noexcept override { return data_.size(); }

  void clear() noexcept { data_.clear(); }
  void reserve(std::size_t n) { data_.reserve(n); }
  void heapify() { complHeapHeapifyFloyd(data_, comp_); }

  void rebuildFrom(std::vector<T> values) {
    data_ = std::move(values);
    heapify();
  }

  const std::vector<T> &data() const noexcept { return data_; }
  static constexpr std::size_t parent(std::size_t i) noexcept {
    return pqParent(i);
  }
  static constexpr std::size_t left(std::size_t i) noexcept {
    return pqLeftChild(i);
  }
  static constexpr std::size_t right(std::size_t i) noexcept {
    return pqRightChild(i);
  }

  bool isValidHeap() const {
    // MOD-A6-B5: validacion explicita de la propiedad heap.
    return complHeapIsValid(data_, comp_);
  }

  bool isHeap() const {
    // MOD-A6-B5: se mantiene compatibilidad con las pruebas existentes.
    return isValidHeap();
  }

private:
  std::vector<T> data_;
  Compare comp_{};
};

} // namespace ods
