#ifndef COMPROG_FENWICKTREE_HPP
#define COMPROG_FENWICKTREE_HPP 1

#include <cassert>
#include <vector>

namespace cp {

template <class T, T (*op)(T, T), T (*op_inv)(T, T), T (*e)()>
struct fenwick {
  int n;
  std::vector<T> data;

  fenwick() : n(0) {}
  fenwick(int n) : n(n), data(n) {
    for (int i = 0; i < n; ++i) data[i] = e();
  }

  void act(int i, T val) {
    for (i++; i <= n; i += i & -i)
      data[i-1] = op(data[i-1], val);
  }

  // [0, i]
  T product(int i) {
    T res = e();
    for (i++; i > 0; i -= i & -i)
      res = op(res, data[i-1]);
    return res;
  }

  T product(int i, int j) {
    if (i == 0)  return product(j);
    return op_inv(product(j), product(i-1));
  }
};

}  // namespace cp

#endif  // COMPROG_FENWICKTREE_HPP
