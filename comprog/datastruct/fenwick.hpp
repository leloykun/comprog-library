#ifndef COMPROG_FENWICKTREE_HPP
#define COMPROG_FENWICKTREE_HPP 1

#include <cassert>
#include <vector>

namespace cp {

template <class T, T (*op)(T, T), T (*inv)(T), T (*e)()>
struct fenwick {
  int n;
  std::vector<T> data;

  fenwick() : n(0) {}
  fenwick(int n) : n(n), data(n) {}

  void act(int i, int val) {
    for (; i < n; i |= i+1)
      data[i] = op(data[i], val);
  }

  // [0, i]
  T product(int i) {
    T res = 0;
    for (; i >= 0; i = (i & (i+1)) - 1)
      res = op(res, data[i]);
    return res;
  }

  int product(int i, int j) {
    if (i == 0)  return product(j);
    return product(j) - product(i-1);
  }
};

}  // namespace cp

#endif  // COMPROG_FENWICKTREE_HPP
