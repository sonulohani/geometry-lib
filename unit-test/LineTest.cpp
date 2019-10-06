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

#include "Line.h"
#include "gtest/gtest.h"

TEST(LineTest, TestDefaultCtor) {
  slohani::Line<int> line;
  EXPECT_EQ(line.x1(), int{});
  EXPECT_EQ(line.y1(), int{});
  EXPECT_EQ(line.x2(), int{});
  EXPECT_EQ(line.y2(), int{});
}

TEST(LineTest, TestParamCtor) {
  slohani::Line<int> line1(5, 6, 7, 8);
  EXPECT_EQ(line1.x1(), 5);
  EXPECT_EQ(line1.y1(), 6);
  EXPECT_EQ(line1.x2(), 7);
  EXPECT_EQ(line1.y2(), 8);

  slohani::Line<float> line2(5.7f, 6.3f, 7.5f, 8.12f);
  EXPECT_FLOAT_EQ(line2.x1(), 5.7f);
  EXPECT_FLOAT_EQ(line2.y1(), 6.3f);
  EXPECT_FLOAT_EQ(line2.x2(), 7.5f);
  EXPECT_FLOAT_EQ(line2.y2(), 8.12f);
}

TEST(LineTest, TestPointGetterMethod) {
  slohani::Line<int> line1(5, 6, 7, 8);
  EXPECT_EQ(line1.p1(), slohani::Point<int>(5, 6));
  EXPECT_EQ(line1.p2(), slohani::Point<int>(7, 8));

  slohani::Line<float> line2(5.7f, 6.3f, 7.5f, 8.12f);
  EXPECT_EQ(line2.p1(), slohani::Point<float>(5.7f, 6.3f));
  EXPECT_EQ(line2.p2(), slohani::Point<float>(7.5f, 8.12f));
}
