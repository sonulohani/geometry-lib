/*
MIT License

Copyright(c) 2018 Sonu Lohani

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
