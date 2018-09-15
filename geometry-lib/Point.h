#pragma once

#include "Common.h"

#include <limits>
#include <type_traits>
#include <exception>
#include <ostream>

namespace slohani {

	template <typename T = int>
	class Point {
	public:
		explicit Point() = default;

		explicit Point(T xPos, T yPos) {
			m_xPos = xPos;
			m_yPos = yPos;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			inline T isNull() const {
			return (m_xPos == 0 && m_yPos == 0);
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			inline T isNull() const {
			return (std::abs(m_xPos) < std::numeric_limits<U>::epsilon() &&
				std::abs(m_yPos) < std::numeric_limits<U>::epsilon());
		}

		inline void setX(T xPos) { m_xPos = xPos; }

		inline void setY(T yPos) { m_yPos = yPos; }

		inline T getX() const { return m_xPos; }

		inline T getY() const { return m_yPos; }

		Point<T>& operator+(const Point<T> point) {
			m_xPos += point.getX();
			m_yPos += point.getY();
			return *this;
		}

		Point<T>& operator+(T value) {
			m_xPos += value;
			m_yPos += value;
			return *this;
		}

		Point<T>& operator-(const Point<T> point) {
			m_xPos -= point.getX();
			m_yPos -= point.getY();
			return *this;
		}

		Point<T>& operator-(T value) {
			m_xPos -= value;
			m_yPos -= value;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			Point<T>& operator*(T factor) {
			if (factor == 1)
			{
				return *this;
			}

			m_xPos *= factor;
			m_yPos *= factor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			Point<T>& operator*(T factor) {
			if (factor == 1.0)
			{
				return *this;
			}

			m_xPos *= factor;
			m_yPos *= factor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			Point<T>& operator/(T divisor) {
			if (divisor == 0) {
				throw std::exception("Cannot divide by zero!");
			}

			if (divisor == 1) {
				return *this;
			}

			m_xPos /= divisor;
			m_yPos /= divisor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			Point<T>& operator/(T divisor) {
			if (divisor == 0.0) {
				throw std::exception("Cannot divide by zero!");
			}

			if (divisor == 1) {
				return *this;
			}

			m_xPos /= divisor;
			m_yPos /= divisor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			bool operator==(const Point<U>& point) {
			return ((*this - point) == 0);
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			bool operator==(const Point<U>& point) {
			return std::abs(this->getX() - point.getX()) < std::numeric_limits<U>::epsilon() &&
				std::abs(this->getY() - point.getY()) < std::numeric_limits<U>::epsilon();
		}

	private:
		friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
			return os << "Point: (" << point.m_xPos << "," << point.m_yPos << ")";
		}

	private:
		T m_xPos = {};
		T m_yPos = {};
	};
} // namespace slohani
