#include <cstddef>
#include <gtest/gtest.h>
#include <rose/vecmath.hpp>

using rose::Vec4;
using rose::Mat3x3;
using rose::Mat3x4;
using rose::Mat4x3;
using rose::Mat4x4;
using rose::vecmath::Mat;

template<class TYPE, size_t COLS, size_t ROWS>
void expect_mat_eq(Mat<TYPE, COLS, ROWS>& m1, Mat<TYPE, COLS, ROWS>& m2) {
  for (int i = 0; i < COLS; ++i) {
    for (int j = 0; j < ROWS; ++j) {
        EXPECT_EQ(m1[i][j], m2[i][j]);
    }
  }
}

template<size_t COLS, size_t ROWS>
void expect_mat_eq(Mat<float, COLS, ROWS>& m1, Mat<float, COLS, ROWS>& m2) {
  for (int i = 0; i < COLS; ++i) {
    for (int j = 0; j < ROWS; ++j) {
        EXPECT_FLOAT_EQ(m1[i][j], m2[i][j]);
    }
  }
}

TEST(Mat, col) {
  Mat3x3<int> mat = {{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  }};

  auto col0 = mat.col(0);
  EXPECT_EQ(col0[0], 1);
  EXPECT_EQ(col0[1], 2);
  EXPECT_EQ(col0[2], 3);

  auto col2 = mat[2];
  EXPECT_EQ(col2[0], 7);
  EXPECT_EQ(col2[1], 8);
  EXPECT_EQ(col2[2], 9);

  EXPECT_EQ(mat[1][2], 6);
}

TEST(Mat4x4, col) {
  Mat4x4<int> mat = {{
    {1,  2,  3,  4 },
    {5,  6,  7,  8 },
    {9,  10, 11, 12},
    {13, 14, 15, 16}
  }};

  auto col0 = mat.col(0);
  EXPECT_EQ(col0[0], 1);
  EXPECT_EQ(col0[1], 2);
  EXPECT_EQ(col0[2], 3);
  EXPECT_EQ(col0[3], 4);

  auto col2 = mat[2];
  EXPECT_EQ(col2[0], 9);
  EXPECT_EQ(col2[1], 10);
  EXPECT_EQ(col2[2], 11);
  EXPECT_EQ(col2[3], 12);

  EXPECT_EQ(mat[1][2], 7);
  EXPECT_EQ(mat[3][1], 14);
}

TEST(Mat4x4, mul) {
  Mat4x4<int> mat1 = {{
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {2, 2, 2, 2},
    {3, 3, 3, 3}
  }};
  Mat4x4<int> mat2 = {{
    {1,  2,  3,  4 },
    {5,  6,  7,  8 },
    {9,  10, 11, 12},
    {13, 14, 15, 16}
  }};

  Mat4x4<int> expected = {{
    {20, 20, 20, 20},
    {44, 44, 44, 44},
    {68, 68, 68, 68},
    {92, 92, 92, 92}
  }};

  auto res = mat1 * mat2;
  expect_mat_eq(res, expected);

  mat1 *= mat2;
  expect_mat_eq(mat1, expected);
}

TEST(Mat, identity) {
  auto mat33 = Mat3x3<float>::identity();
  Mat3x3<float> expected33 = {{
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f}
  }};
  expect_mat_eq(mat33, expected33);

  auto mat43 = Mat4x3<float>::identity();
  Mat4x3<float> expected43 = {{
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {0.0f, 0.0f, 0.0f}
  }};
  expect_mat_eq(mat43, expected43);

  auto mat34 = Mat3x4<float>::identity();
  Mat3x4<float> expected34 = {{
    {1.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 1.0f, 0.0f}
  }};
  expect_mat_eq(mat34, expected34);
}

TEST(Mat4x4, identity) {
  auto mat = Mat4x4<float>::identity();

  Mat4x4<float> expected = {{
    {1.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f}
  }};

  expect_mat_eq(mat, expected);
}

TEST(Mat4x4, ortho) {
  auto mat = Mat4x4<float>::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f);

  Mat4x4<float> expected = {{
    {1.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f}
  }};

  expect_mat_eq(mat, expected);
}
