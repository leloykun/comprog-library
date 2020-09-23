#ifndef COMPROG_MONOID_HPP
#define COMPROG_MONOID_HPP 1

#include <functional>

namespace cp {

// op need not be commutative
template <class T>
struct monoid {
  const T id;
  const std::function<T(T,T)> op;
};

}  // namespace cp

#endif  // COMPROG_MONOID_HPP
