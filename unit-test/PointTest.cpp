#include "Point.h"
#include "gtest/gtest.h"

TEST(PointTest, EmptyCtorTest) {
  slohani::Point<int> p1;
  EXPECT_TRUE(p1.isNull());

  slohani::Point<float> p2;
  EXPECT_TRUE(p2.isNull());
}

TEST(PointTest, ParameterizedCtorTest) {
  slohani::Point<int> p1(5, 6);
  EXPECT_EQ(5, p1.getX());
  EXPECT_EQ(6, p1.getY());

  slohani::Point<float> p2(5.6f, 6.5f);
  EXPECT_FLOAT_EQ(5.6f, p2.getX());
  EXPECT_FLOAT_EQ(6.5f, p2.getY());
}
TEST(PointTest, IsNullTest) {
  slohani::Point<int> p1;
  EXPECT_TRUE(p1.isNull());
  EXPECT_EQ(0, p1.getX());
  EXPECT_EQ(0, p1.getY());

  slohani::Point<float> p2;
  EXPECT_TRUE(p2.isNull());
  EXPECT_EQ(0.f, p2.getX());
  EXPECT_EQ(0.f, p2.getY());

  slohani::Point<float> p3(0.f, 5.0f);
  EXPECT_FALSE(p3.isNull());

  slohani::Point<float> p4(0.f, 5.0f);
  EXPECT_FALSE(p4.isNull());

  slohani::Point<float> p5(0.5f, 0.f);
  EXPECT_FALSE(p5.isNull());

  slohani::Point<float> p6(0.f, 0.f);
  EXPECT_TRUE(p6.isNull());
}

TEST(PointTest, TestSetAndGet) {
  slohani::Point<int> p1;
  EXPECT_TRUE(p1.isNull());

  p1.setX(6);
  p1.setY(7);
  EXPECT_EQ(6, p1.getX());
  EXPECT_EQ(7, p1.getY());

  slohani::Point<double> p2;
  EXPECT_TRUE(p2.isNull());

  p2.setX(6.789);
  p2.setY(7.654);
  EXPECT_EQ(6.789, p2.getX());
  EXPECT_EQ(7.654, p2.getY());
}

TEST(PointTest, TestAddingPoints) {
  slohani::Point<int> p1(9, 8);
  slohani::Point<int> p2(7, 5);

  auto p3 = p1 + p2;

  EXPECT_EQ(9, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(16, p3.getX());
  EXPECT_EQ(13, p3.getY());

  auto p4 = p1 + p2 + p3;

  EXPECT_EQ(32, p4.getX());
  EXPECT_EQ(26, p4.getY());

  p4 = p4 + 5;

  EXPECT_EQ(37, p4.getX());
  EXPECT_EQ(31, p4.getY());

  p4 += 3;

  EXPECT_EQ(40, p4.getX());
  EXPECT_EQ(34, p4.getY());

  p4 += slohani::Point<int>(5, 6);

  EXPECT_EQ(9, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(45, p4.getX());
  EXPECT_EQ(40, p4.getY());
}

TEST(PointTest, TestSubtractingPoints) {
  slohani::Point<int> p1(9, 8);
  slohani::Point<int> p2(7, 5);

  auto p3 = p1 - p2;

  EXPECT_EQ(9, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(2, p3.getX());
  EXPECT_EQ(3, p3.getY());

  auto p4 = p1 - p2 - p3;

  EXPECT_TRUE(p4.isNull());

  p4 = p4 - 5;

  EXPECT_EQ(-5, p4.getX());
  EXPECT_EQ(-5, p4.getY());

  p4 -= 3;

  EXPECT_EQ(-8, p4.getX());
  EXPECT_EQ(-8, p4.getY());

  p4 -= slohani::Point<int>(5, -6);

  EXPECT_EQ(9, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(-13, p4.getX());
  EXPECT_EQ(-2, p4.getY());
}

TEST(PointTest, TestMultiplyingPoints) {
  slohani::Point<int> p1(9, 8);

  auto p2 = p1 * 3;

  EXPECT_EQ(9, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(27, p2.getX());
  EXPECT_EQ(24, p2.getY());

  p2 *= 5;

  EXPECT_EQ(9, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(135, p2.getX());
  EXPECT_EQ(120, p2.getY());
}

TEST(PointTest, TestDividingPoints) {
  slohani::Point<int> p1(4, 8);

  auto p2 = p1 / 2;

  EXPECT_EQ(4, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(2, p2.getX());
  EXPECT_EQ(4, p2.getY());

  p2 /= 2;

  EXPECT_EQ(4, p1.getX());
  EXPECT_EQ(8, p1.getY());

  EXPECT_EQ(1, p2.getX());
  EXPECT_EQ(2, p2.getY());
}

TEST(PointTest, TestComparingPointsIsEqual) {
  slohani::Point<int> p1(4, 8);
  slohani::Point<int> p2(4, 8);

  EXPECT_EQ(p1, p2);

  slohani::Point<double> p3(4.56, 7.89);
  slohani::Point<double> p4(4.56, 7.89);

  EXPECT_EQ(p3, p4);
}

TEST(PointTest, TestComparingPointsIsUnEqual) {
  slohani::Point<int> p1(4, 8);
  slohani::Point<int> p2(4, 9);
  slohani::Point<int> p3(5, 8);

  EXPECT_NE(p1, p2);
  EXPECT_NE(p1, p3);
  EXPECT_NE(p2, p3);

  slohani::Point<double> p4(4.56, 7.89);
  slohani::Point<double> p5(4.56, 7.8);
  slohani::Point<double> p6(4.5, 7.89);

  EXPECT_NE(p4, p5);
  EXPECT_NE(p5, p6);
  EXPECT_NE(p6, p4);
}

TEST(PointTest, TestDotProduct) {
  slohani::Point<double> p1(3.1, 7.1);
  slohani::Point<double> p2(-1.0, 4.1);

  EXPECT_DOUBLE_EQ(26.01, slohani::Point<double>::dotProduct(p1, p2));
}
