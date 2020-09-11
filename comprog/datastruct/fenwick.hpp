#ifndef COMPROG_FENWICKTREE_HPP
#define COMPROG_FENWICKTREE_HPP 1

#include <cassert>
#include <vector>

namespace cp {

template <class T, T (*op)(T, T), T (*invert)(T), T (*e)()>
struct fenwick {
  int n;
  std::vector<T> data;

  fenwick() : n(0) {}
  fenwick(int n) : n(n), data(n) {}

  void act(int p, T x) {
    assert(0 <= p && p < n);
    p++;
    while (p <= n) {
      data[p - 1] = op(data[p - 1], x);
      p += p & -p;
    }
  }

  // [0, r-1]
  T product(int r) {
    T s = e();
    while (r > 0) {
      s = op(s, data[r - 1]);
      r -= r & -r;
    }
    return s;
  }

  // [l, r-1]
  T product(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    return op(product(r), invert(product(l)));
  }
};

}  // namespace cp

#endif  // COMPROG_FENWICKTREE_HPP
