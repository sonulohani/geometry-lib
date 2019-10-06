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

#include "Common.h"

#include <exception>
#include <initializer_list>
#include <ostream>
#include <type_traits>

namespace slohani {

template <typename T>
class Point {
 public:
  explicit constexpr Point() = default;

  explicit constexpr Point(T xPos, T yPos) : m_xPos{xPos}, m_yPos{yPos} {}

  constexpr inline auto isNull() const {
    return common::compare(m_xPos, static_cast<T>(0)) ==
               common::CompareCode::EQUAL &&
           common::compare(m_yPos, static_cast<T>(0)) ==
               common::CompareCode::EQUAL;
  }

  inline constexpr void setX(T xPos) { m_xPos = xPos; }

  inline constexpr void setY(T yPos) { m_yPos = yPos; }

  inline constexpr auto getX() const { return m_xPos; }

  inline constexpr auto getY() const { return m_yPos; }

  constexpr auto operator+(const Point<T>& point) const {
    Point<T> returnedPoint = *this;
    returnedPoint.m_xPos += point.getX();
    returnedPoint.m_yPos += point.getY();
    return returnedPoint;
  }

  constexpr auto operator+(T value) const {
    Point<T> returnedPoint = *this;
    returnedPoint.m_xPos += value;
    returnedPoint.m_yPos += value;
    return returnedPoint;
  }

  constexpr auto operator+=(const Point<T>& point) -> Point<T>& {
    m_xPos += point.getX();
    m_yPos += point.getY();
    return *this;
  }

  constexpr auto operator+=(T value) -> Point<T>& {
    m_xPos += value;
    m_yPos += value;
    return *this;
  }

  constexpr auto operator-(const Point<T>& point) const {
    Point<T> returnedPoint = *this;
    returnedPoint.m_xPos -= point.getX();
    returnedPoint.m_yPos -= point.getY();
    return returnedPoint;
  }

  constexpr auto operator-(T value) const {
    Point<T> returnedPoint = *this;
    returnedPoint.m_xPos -= value;
    returnedPoint.m_yPos -= value;
    return returnedPoint;
  }

  constexpr auto operator-=(const Point<T>& point) -> Point<T>& {
    m_xPos -= point.getX();
    m_yPos -= point.getY();
    return *this;
  }

  constexpr auto operator-=(T value) -> Point<T>& {
    m_xPos -= value;
    m_yPos -= value;
    return *this;
  }

  constexpr auto operator*(T factor) const {
    if (factor == static_cast<T>(1)) {
      return *this;
    }

    Point<T> returnedPoint = *this;
    returnedPoint.m_xPos *= factor;
    returnedPoint.m_yPos *= factor;
    return returnedPoint;
  }

  constexpr auto operator*=(T factor) -> Point<T>& {
    if (factor == static_cast<T>(1)) {
      return *this;
    }

    m_xPos *= factor;
    m_yPos *= factor;
    return *this;
  }

  constexpr auto operator/(T divisor) const {
    if (common::compare(divisor, static_cast<T>(0)) ==
        common::CompareCode::EQUAL) {
      throw std::exception("Cannot divide by zero!");
    }

    Point<T> returnedPoint = *this;
    returnedPoint.m_xPos /= divisor;
    returnedPoint.m_yPos /= divisor;
    return returnedPoint;
  }

  constexpr auto operator/=(T divisor) -> Point<T>& {
    if (common::compare(divisor, static_cast<T>(0)) ==
        common::CompareCode::EQUAL) {
      throw std::exception("Cannot divide by zero!");
    }

    m_xPos /= divisor;
    m_yPos /= divisor;
    return *this;
  }

  constexpr auto operator==(const Point<T>& point) const {
    return common::compare(m_xPos, point.m_xPos) ==
               common::CompareCode::EQUAL &&
           common::compare(m_yPos, point.m_yPos) == common::CompareCode::EQUAL;
  }

  constexpr auto operator!=(const Point<T>& point) const {
    return common::compare(m_xPos, point.m_xPos) !=
               common::CompareCode::EQUAL ||
           common::compare(m_yPos, point.m_yPos) != common::CompareCode::EQUAL;
  }

  constexpr static auto dotProduct(const Point<T>& p1, const Point<T>& p2) {
    return p1.getX() * p2.getX() + p1.getY() * p2.getY();
  }

 private:
  friend auto operator<<(std::ostream& os, const Point<T>& point)
      -> std::ostream& {
    return os << "Point: (" << point.m_xPos << "," << point.m_yPos << ")";
  }

 private:
  T m_xPos = {};
  T m_yPos = {};
};
}  // namespace slohani
