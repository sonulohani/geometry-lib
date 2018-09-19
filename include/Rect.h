#pragma once

#include "Point.h"

#include <type_traits>

namespace slohani {
	template<typename T>
	class Rect {
	public:
		explicit constexpr Rect() = default;

		explicit constexpr Rect(const Point<T>& topLeft, const Point<T>& bottomRight) {
			mX = topLeft.getX();
			mY = topLeft.getY();
			mWidth = bottomRight.getX() - topLeft.getX();
			mWidth = bottomRight.getY() - topLeft.getY();
		}

		explicit constexpr Rect(T x, T y, T width, T height) {
			mX = x;
			mY = y;
			mWidth = width;
			mHeight = height;
		}

		// TBD
		//Rect(const QPoint &topLeft, const Size &size)

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
		constexpr inline bool isNull() const {
			return mWidth == 0 && mHeight == 0;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
		constexpr inline bool isNull() const {
			return mWidth == 0.0 && mHeight == 0.0;
		}

		template <typename U = T,
			std::enable_if_t<std::is_integral_v<U>, U>* = nullptr>
		constexpr inline bool isValid() const {
			return mWidth > 0 && mHeight > 0;
		}

		template <typename U = T,
			std::enable_if_t<std::is_floating_point_v<U>, U>* = nullptr>
		constexpr inline bool isValid() const {
			return mWidth > 0.0 && mHeight > 0.0;
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

		constexpr inline T getWidth() const {
			return mWidth;
		}

		constexpr inline T getHeight() const {
			return mHeight;
		}

		constexpr inline T getX() const {
			return mX;
		}

		constexpr inline T getT() const {
			return mY;
		}

		constexpr inline Point<T> center() const {
			return Point<T>(mX + mWidth/2, mY + mHeight/2);
		}

	private:
		friend std::ostream& operator<<(std::ostream& os, const Rect<T>& rect) {
			return os << "Rect: ( x : " << rect.getX() << ", y : " << 
			rect.getX() << ", width : " << rect.getHeight() << 
			", height: " << rect.getHeight() << ")";
		}


		
	private:
		T mX = {}; 
		T mY = {};
		T mWidth = {};
		T mHeight = {};
	};
}
