#ifndef COMPROG_GROUP_HPP
#define COMPROG_GROUP_HPP 1

#include <functional>

namespace cp {

// op need not be commutative
template <class T>
struct group {
  const T id;
  const std::function<T(T,T)> op;
  const std::function<T(T)> inv;
  T op_inv(T x, T y) { op(x, inv(y)); };
};

}  // namespace cp

#endif  // COMPROG_GROUP_HPP
