#include <gtest/gtest.h>
#include <rose/vecmath.hpp>

using rose::Vec3;

TEST(Vec, initialization) {
  Vec3<float> vec = {1.0, 2.0, 3.0};
  EXPECT_FLOAT_EQ(vec.vec[0], 1.0);
  EXPECT_FLOAT_EQ(vec.vec[1], 2.0);
  EXPECT_FLOAT_EQ(vec.vec[2], 3.0);
}

TEST(Vec, get) {
  Vec3<int> vec = {1, 2, 3};
  EXPECT_EQ(vec.get(0), 1);
  EXPECT_EQ(vec.get(1), 2);
  EXPECT_EQ(vec.get(2), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);

  vec.get(0) = 3;
  vec[1] = 3;
  EXPECT_EQ(vec[0], 3);
  EXPECT_EQ(vec[1], 3);
}
