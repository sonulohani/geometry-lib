#pragma once

#include <limits>

namespace slohani {
namespace common {
enum class CompareCode : int8_t { GREATER = -1, EQUAL, LESS };

template <typename T>
auto compare(const T first, const T second) {
  if (first == second) {
    return CompareCode::EQUAL;
  }
  if (first > second) {
    return CompareCode::GREATER;
  }
  return CompareCode::LESS;
}

template <>
auto compare<float>(const float first, const float second) {
  if (std::abs(first - second) < std::numeric_limits<float>::epsilon()) {
    return CompareCode::EQUAL;
  }
  if (first > second) {
    return CompareCode::GREATER;
  }
  return CompareCode::LESS;
}

template <>
auto compare<double>(const double first, const double second) {
  if (std::abs(first - second) < std::numeric_limits<double>::epsilon()) {
    return CompareCode::EQUAL;
  }
  if (first > second) {
    return CompareCode::GREATER;
  }
  return CompareCode::LESS;
}
}  // namespace common
}  // namespace slohani
