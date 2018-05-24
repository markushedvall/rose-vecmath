#ifndef ROSE_VECMATH_VEC_HPP
#define ROSE_VECMATH_VEC_HPP

#include <cstddef>

namespace rose {
  namespace vecmath {

    template<class TYPE, size_t LENGTH>
    struct Vec {
      TYPE vec[LENGTH];

      TYPE& get(size_t index) noexcept {
        return vec[index];
      }

      const TYPE& get(size_t index) const noexcept {
        return vec[index];
      }

      TYPE& operator[](size_t index) noexcept {
        return get(index);
      }

      const TYPE& operator[](size_t index) const noexcept {
        return get(index);
      }
    };

  }
}

#endif
