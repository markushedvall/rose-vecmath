#include <gtest/gtest.h>
#include <rose/vecmath.hpp>

using rose::traits::One;

TEST(One, float) {
  EXPECT_FLOAT_EQ(One<float>::one(), 1.0f);
}

TEST(One, double) {
  EXPECT_DOUBLE_EQ(One<double>::one(), 1.0);
}

TEST(One, longdouble) {
  EXPECT_DOUBLE_EQ(One<long double>::one(), 1.0);
}
