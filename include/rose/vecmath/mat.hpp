#ifndef ROSE_VECMATH_MAT_HPP
#define ROSE_VECMATH_MAT_HPP

#include <cstddef>
#include <cmath>

#include "vec.hpp"
#include "../traits/traits.hpp"

namespace rose {
  namespace vecmath {

    template<class TYPE, size_t ROWS, size_t COLS>
    struct Mat {
      static constexpr TYPE one = traits::One<TYPE>::one();
      Vec<TYPE, ROWS> mat[COLS];

      Vec<TYPE, ROWS>& col(size_t index) noexcept {
        return mat[index];
      }

      const Vec<TYPE, ROWS>& col(size_t index) const noexcept {
        return mat[index];
      }

      Vec<TYPE, ROWS>& operator[](size_t index) noexcept {
        return col(index);
      }

      const Vec<TYPE, ROWS>& operator[](size_t index) const noexcept {
        return col(index);
      }

      static Mat<TYPE, ROWS, COLS> identity() noexcept {
        Mat<TYPE, ROWS, COLS> m;
        for (int i = 0; i < COLS; ++i) {
          for (int j = 0; j < ROWS; ++j) {
              m[i][j] = i == j ? one : 0;
          }
        }
        return m;
      }

    };

    template<class TYPE>
    struct Mat<TYPE, 4, 4> {

      static constexpr TYPE one = traits::One<TYPE>::one();
      Vec<TYPE, 4> mat[4];

      Vec<TYPE, 4>& col(size_t index) noexcept {
        return mat[index];
      }

      const Vec<TYPE, 4>& col(size_t index) const noexcept {
        return mat[index];
      }

      Vec<TYPE, 4>& operator[](size_t index) noexcept {
        return col(index);
      }

      const Vec<TYPE, 4>& operator[](size_t index) const noexcept {
        return col(index);
      }

      const Mat<TYPE, 4, 4> operator*(const Mat<TYPE, 4, 4>& other)
      const noexcept {
        Mat<TYPE, 4, 4> res;
        for (int c = 0; c < 4; ++c) {
          for (int r = 0; r < 4; ++r) {
            res[c][r] = 0;
            for (int k = 0; k < 4; ++k) {
              res[c][r] += mat[k][r] * other[c][k];
            }
          }
        }
        return res;
      }

      Mat<TYPE, 4, 4>& operator*=(const Mat<TYPE, 4, 4>& other) noexcept {
        *this = *this * other;
        return *this;
      }

      void rotate_x(float angle) noexcept {
        auto rot = rotation_x(angle);
        *this *= rot;
      }

      void rotate_y(float angle) noexcept {
        auto rot = rotation_y(angle);
        *this *= rot;
      }

      void rotate_z(float angle) noexcept {
        auto rot = rotation_z(angle);
        *this *= rot;
      }

      static Mat<TYPE, 4, 4> identity() noexcept {
        return {{
          {one, 0,   0,   0  },
          {0,   one, 0,   0  },
          {0,   0,   one, 0  },
          {0,   0,   0,   one}
        }};
      }

      static Mat<TYPE, 4, 4> ortho(TYPE left, TYPE right, TYPE bottom, TYPE top,
                                   TYPE near, TYPE far) noexcept {
        TYPE rl = right + left;
        TYPE tb = top + bottom;
        TYPE nf = near + far;
        TYPE irl = one / (right - left);
        TYPE itb = one / (top - bottom);
        TYPE inf = one / (near - far);
        return {{
          { irl + irl, 0,         0,         0  },
          { 0,         itb + itb, 0,         0  },
          { 0,         0,         inf + inf, 0  },
          {-rl * irl, -tb * itb,  nf * inf,  one}
        }};
      }

      static Mat<TYPE, 4, 4> rotation_x(float angle) {
        TYPE s = (TYPE) sinf(angle);
        TYPE c = (TYPE) cosf(angle);
        return {{
          {one, 0,   0,   0  },
          {0,   c,   s,   0  },
          {0,  -s,   c,   0  },
          {0,   0,   0,   one}
        }};
      }

      static Mat<TYPE, 4, 4> rotation_y(float angle) {
        TYPE s = (TYPE) sinf(angle);
        TYPE c = (TYPE) cosf(angle);
        return {{
          {c,   0,  -s,   0  },
          {0,   one, 0,   0  },
          {s,   0,   c,   0  },
          {0,   0,   0,   one}
        }};
      }

      static Mat<TYPE, 4, 4> rotation_z(float angle) {
        TYPE s = (TYPE) sinf(angle);
        TYPE c = (TYPE) cosf(angle);
        return {{
          { c,   s,   0,   0  },
          {-s,   c,   0,   0  },
          { 0,   0,   one, 0  },
          { 0,   0,   0,   one}
        }};
      }

    };

  }
}

#endif
