#pragma once

#include "gtest/gtest.h"
#include "Point.h"

TEST(PointTest, Ctor_Test)
{
	slohani::Point<> p;
	EXPECT_TRUE(p.isNull());
}
