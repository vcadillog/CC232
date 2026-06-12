#pragma once

#include <cstddef>

namespace ods {

inline constexpr std::size_t pqParent(std::size_t i) noexcept {
  return (i - 1) / 2;
}
inline constexpr std::size_t pqLeftChild(std::size_t i) noexcept {
  return 2 * i + 1;
}
inline constexpr std::size_t pqRightChild(std::size_t i) noexcept {
  return 2 * i + 2;
}
inline constexpr bool pqInHeap(std::size_t i, std::size_t n) noexcept {
  return i < n;
}
inline constexpr bool pqHasParent(std::size_t i) noexcept { return i > 0; }
inline constexpr std::size_t pqLastInternal(std::size_t n) noexcept {
  return n == 0 ? 0 : pqParent(n - 1);
}

// MOD-A6-B2: utilidades auxiliares para frontera en heap completo.
inline constexpr bool pqHasLeftChild(std::size_t i, std::size_t n) noexcept {
  return pqInHeap(i, n) && pqInHeap(pqLeftChild(i), n);
}

// MOD-A6-B2: verifica si existe hijo derecho en la representacion implicita.
inline constexpr bool pqHasRightChild(std::size_t i, std::size_t n) noexcept {
  return pqInHeap(i, n) && pqInHeap(pqRightChild(i), n);
}

// MOD-A6-B2: una hoja pertenece al heap y no tiene hijo izquierdo.
inline constexpr bool pqIsLeaf(std::size_t i, std::size_t n) noexcept {
  return pqInHeap(i, n) && !pqHasLeftChild(i, n);
}

// MOD-A6-B2: un nodo interno pertenece al heap y tiene al menos hijo izquierdo.
inline constexpr bool pqIsInternal(std::size_t i, std::size_t n) noexcept {
  return pqInHeap(i, n) && pqHasLeftChild(i, n);
}
} // namespace ods
