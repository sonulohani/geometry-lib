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

#include "Point.h"

#include <type_traits>

namespace slohani {
template <typename T>
class Rect {
 public:
  explicit constexpr Rect() = default;

  explicit constexpr Rect(const Point<T>& topLeft,
                          const Point<T>& bottomRight) {
    m_xPos = topLeft.getX();
    m_yPos = topLeft.getY();
    m_width = bottomRight.getX() - topLeft.getX();
    m_width = bottomRight.getY() - topLeft.getY();
  }

  explicit constexpr Rect(T x, T y, T width, T height) {
    m_xPos = x;
    m_yPos = y;
    m_width = width;
    m_height = height;
  }

  constexpr Rect(const Rect<T>& obj) = default;
  constexpr Rect& operator=(const Rect<T>& obj) = default;
  constexpr Rect(Rect<T>&& obj) = default;
  constexpr Rect& operator=(Rect<T>&& obj) = default;

  // TBD
  // Rect(const QPoint &topLeft, const Size &size)

  template <typename U = T,
            std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
  constexpr inline bool isNull() const {
    return m_width == 0 && m_height == 0;
  }

  template <typename U = T,
            std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
  constexpr inline bool isNull() const {
    return m_width == 0.0 && m_height == 0.0;
  }

  template <typename U = T,
            std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
  constexpr inline bool isValid() const {
    return m_width > 0 && m_height > 0;
  }

  template <typename U = T,
            std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
  constexpr inline bool isValid() const {
    return m_width > 0.0 && m_height > 0.0;
  }

  template <typename U = T,
            std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
  constexpr inline bool isEmpty() const {
    return !isValid<U>();
  }

  template <typename U = T,
            std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
  constexpr inline bool isEmpty() const {
    return !isValid<U>();
  }

  constexpr inline T getWidth() const { return m_width; }

  constexpr inline T getHeight() const { return m_height; }

  constexpr inline T getX() const { return m_xPos; }

  constexpr inline T getT() const { return m_yPos; }

  constexpr inline Point<T> center() const {
    return Point<T>(m_xPos + m_width / 2, m_yPos + m_height / 2);
  }

 private:
  friend std::ostream& operator<<(std::ostream& os, const Rect<T>& rect) {
    return os << "Rect: ( x : " << rect.getX() << ", y : " << rect.getX()
              << ", width : " << rect.getHeight()
              << ", height: " << rect.getHeight() << ")";
  }

 private:
  T m_xPos = {};
  T m_yPos = {};
  T m_width = {};
  T m_height = {};
};
}  // namespace slohani
