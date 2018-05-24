#ifndef ROSE_VECMATH_HPP
#define ROSE_VECMATH_HPP

#include "vecmath/vec.hpp"
#include "vecmath/mat.hpp"
#include "traits/traits.hpp"

namespace rose {

  template <class TYPE>
  using Vec2 = vecmath::Vec<TYPE, 2>;

  template <class TYPE>
  using Vec3 = vecmath::Vec<TYPE, 3>;

  template <class TYPE>
  using Vec4 = vecmath::Vec<TYPE, 4>;

  template <class TYPE>
  using Mat2x2 = vecmath::Mat<TYPE, 2, 2>;

  template <class TYPE>
  using Mat2x3 = vecmath::Mat<TYPE, 2, 3>;

  template <class TYPE>
  using Mat2x4 = vecmath::Mat<TYPE, 2, 4>;

  template <class TYPE>
  using Mat3x2 = vecmath::Mat<TYPE, 3, 2>;

  template <class TYPE>
  using Mat3x3 = vecmath::Mat<TYPE, 3, 3>;

  template <class TYPE>
  using Mat3x4 = vecmath::Mat<TYPE, 3, 4>;

  template <class TYPE>
  using Mat4x2 = vecmath::Mat<TYPE, 4, 2>;

  template <class TYPE>
  using Mat4x3 = vecmath::Mat<TYPE, 4, 3>;

  template <class TYPE>
  using Mat4x4 = vecmath::Mat<TYPE, 4, 4>;

}

#endif
