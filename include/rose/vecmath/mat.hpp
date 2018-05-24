#ifndef ROSE_VECMATH_MAT_HPP
#define ROSE_VECMATH_MAT_HPP

#include <cstddef>

#include "vec.hpp"
#include "../traits/traits.hpp"

namespace rose {
  namespace vecmath {

    template<class TYPE, size_t COLS, size_t ROWS>
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

      static Mat<TYPE, COLS, ROWS> identity() noexcept {
        Mat<TYPE, COLS, ROWS> m;
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

      static Mat<TYPE, 4, 4> identity() noexcept {
        return {{
          {one, 0,   0,   0  },
          {0,   one, 0,   0  },
          {0,   0,   one, 0  },
          {0,   0,   0,   one}
        }};
      }

    };

  }
}

#endif
