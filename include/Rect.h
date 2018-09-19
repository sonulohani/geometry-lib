#pragma once

#include "Point.h"

namespace slohani {
	template<typename T>
	class Rect {
	public:
		explicit constexpr Rect() = default;

		explicit constexpr Rect(const Point<T>& topLeft, const Point<T>& bottomRight) {
			mX1 = topLeft.getX();
			mY1 = topLeft.getY();
			mX2 = bottomRight.getX();
			mY2 = bottomRight.getY();
		}

		explicit constexpr Rect(T x, T y, T width, T height) {
			mX1 = x;
			mY1 = y;
			mX2 = mX1 + width - 1;
			mY2 = mY1 + height - 1;
		}

		// TBD
		//Rect(const QPoint &topLeft, const Size &size)

		constexpr inline bool isNull() const {
			return mX2 == mX1 - 1 && mY2 == mY1 - 1;
		}


	private:
		T mX1, mY1, mX2, mY2;
	};
}
