#ifndef ROSE_VECMATH_TRAITS_HPP
#define ROSE_VECMATH_TRAITS_HPP

#include <assert.h>
#include <type_traits>

namespace rose {
  namespace traits {

    template<class TYPE> struct One {
      static_assert(sizeof(TYPE) == -1,
      "A specialization of One is required for this type");
    };

    template<>
    struct One<float> {
      static constexpr float one() noexcept {
        return 1.0f;
      }
    };

    template<>
    struct One<double> {
      static constexpr double one() noexcept {
        return 1.0;
      }
    };

    template<>
    struct One<long double> {
      static constexpr long double one() noexcept {
        return 1.0;
      }
    };

    template<>
    struct One<int> {
      static constexpr int one() noexcept {
        return 1;
      }
    };

  }
}

#endif
