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

#include <cmath>
#include "Point.h"

namespace slohani {
template <typename T>
class Line {
 public:
  constexpr Line() = default;
  constexpr Line(T x1, T y1, T x2, T y2)
      : m_x1{x1}, m_y1{y1}, m_x2{x2}, m_y2{y2} {}

  constexpr auto p1() const { return Point<T>(m_x1, m_y1); }

  constexpr auto p2() const { return Point<T>(m_x2, m_y2); }

  constexpr auto x1() const { return m_x1; }

  constexpr auto y1() const { return m_y1; }

  constexpr auto x2() const { return m_x2; }

  constexpr auto y2() const { return m_y2; }

  constexpr auto angle() const {
    const auto dx = m_x2 - m_x1;
    const auto dy = m_y2 - m_y1;
    const auto theta = std::atan2(dy, dx) * 180 / M_PI;
    const auto thetaNormalized = theta < 0 ? theta + 360 : theta;
    if (common::compare(thetaNormalized, static_cast<T>(360)) ==
        common::CompareCode::EQUAL) {
      return {};
    }
    return thetaNormalized;
  }

  /*constexpr void setAngle(const double angle) {
    const auto angleR = angle * M_PI / 180.0;

  }*/

 private:
  T m_x1 = {};
  T m_y1 = {};
  T m_x2 = {};
  T m_y2 = {};
};
}  // namespace slohani
