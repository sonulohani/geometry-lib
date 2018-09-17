#pragma once

#include "Common.h"

#include <limits>
#include <type_traits>
#include <exception>
#include <ostream>
#include <initializer_list>

namespace slohani {

	template <typename T>
	class Point {
	public:
		explicit Point() = default;

		explicit Point(T xPos, T yPos) {
			mXPos = xPos;
			mYPos = yPos;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr inline T isNull() const {
			return (mXPos == 0 && mYPos == 0);
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr inline T isNull() const {
			return (std::abs(mXPos) < std::numeric_limits<U>::epsilon() &&
				std::abs(mYPos) < std::numeric_limits<U>::epsilon());
		}

		inline void setX(T xPos) { mXPos = xPos; }

		inline void setY(T yPos) { mYPos = yPos; }

		inline T getX() const { return mXPos; }

		inline T getY() const { return mYPos; }

		constexpr Point<T> operator+(const Point<T>& point) {
			Point<T> returnedPoint = *this;
			returnedPoint.mXPos += point.getX();
			returnedPoint.mYPos += point.getY();
			return returnedPoint;
		}

		constexpr Point<T> operator+(T value) {
			Point<T> returnedPoint = *this;
			returnedPoint.mXPos += value;
			returnedPoint.mYPos += value;
			return returnedPoint;
		}

		constexpr Point<T>& operator+=(const Point<T>& point) {
			mXPos += point.getX();
			mYPos += point.getY();
			return *this;
		}

		constexpr Point<T>& operator+=(T value) {
			mXPos += value;
			mYPos += value;
			return *this;
		}

		constexpr Point<T> operator-(const Point<T>& point) {
			Point<T> returnedPoint = *this;
			returnedPoint.mXPos -= point.getX();
			returnedPoint.mYPos -= point.getY();
			return returnedPoint;
		}

		constexpr Point<T> operator-(T value) {
			Point<T> returnedPoint = *this;
			returnedPoint.mXPos -= value;
			returnedPoint.mYPos -= value;
			return returnedPoint;
		}

		constexpr Point<T>& operator-=(const Point<T>& point) {
			mXPos -= point.getX();
			mYPos -= point.getY();
			return *this;
		}

		constexpr Point<T>& operator-=(T value) {
			mXPos -= value;
			mYPos -= value;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr Point<T> operator*(T factor) {
			if (factor == 1)
			{
				return *this;
			}

			Point<T> returnedPoint = *this;
			returnedPoint.mXPos *= factor;
			returnedPoint.mYPos *= factor;
			return returnedPoint;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr Point<T> operator*(T factor) {
			if (factor == 1.0)
			{
				return *this;
			}

			Point<T> returnedPoint = *this;
			returnedPoint.mXPos *= factor;
			returnedPoint.mYPos *= factor;
			return returnedPoint;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr Point<T>& operator*=(T factor) {
			if (factor == 1)
			{
				return *this;
			}

			mXPos *= factor;
			mYPos *= factor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr Point<T>& operator*=(T factor) {
			if (factor == 1.0)
			{
				return *this;
			}

			mXPos *= factor;
			mYPos *= factor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr Point<T> operator/(T divisor) {
			if (divisor == 0) {
				throw std::exception("Cannot divide by zero!");
			}

			if (divisor == 1) {
				return *this;
			}

			Point<T> returnedPoint = *this;
			returnedPoint.mXPos /= divisor;
			returnedPoint.mYPos /= divisor;
			return returnedPoint;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr Point<T> operator/(T divisor) {
			if (divisor == 0.0) {
				throw std::exception("Cannot divide by zero!");
			}

			if (divisor == 1) {
				return *this;
			}

			Point<T> returnedPoint = *this;
			returnedPoint.mXPos /= divisor;
			returnedPoint.mYPos /= divisor;
			return returnedPoint;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr Point<T>& operator/=(T divisor) {
			if (divisor == 0) {
				throw std::exception("Cannot divide by zero!");
			}

			if (divisor == 1) {
				return *this;
			}

			mXPos /= divisor;
			mYPos /= divisor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr Point<T>& operator/=(T divisor) {
			if (divisor == 0.0) {
				throw std::exception("Cannot divide by zero!");
			}

			if (divisor == 1) {
				return *this;
			}

			mXPos /= divisor;
			mYPos /= divisor;
			return *this;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr bool operator==(const Point<U>& point) const {
			return (mXPos - point.mXPos) == 0 && (mYPos - point.mYPos) == 0;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr bool operator==(const Point<U>& point) const {
			return std::abs(this->getX() - point.getX()) < std::numeric_limits<U>::epsilon() &&
				std::abs(this->getY() - point.getY()) < std::numeric_limits<U>::epsilon();
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
			constexpr bool operator!=(const Point<U>& point) const {
			return (mXPos - point.mXPos) != 0 || (mYPos - point.mYPos) != 0;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
			constexpr bool operator!=(const Point<U>& point) const {
			return std::abs(this->getX() - point.getX()) > std::numeric_limits<U>::epsilon() ||
				std::abs(this->getY() - point.getY()) > std::numeric_limits<U>::epsilon();
		}

		constexpr static T dotProduct(const Point<T>& p1, const Point<T>& p2) {
			return p1.getX() * p2.getX() + p1.getY() * p2.getY();
		}

	private:
		friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
			return os << "Point: (" << point.mXPos << "," << point.mYPos << ")";
		}

	private:
		T mXPos = {};
		T mYPos = {};
	};
} // namespace slohani
