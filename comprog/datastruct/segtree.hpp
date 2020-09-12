#ifndef COMPROG_SEGTREE_HPP
#define COMPROG_SEGTREE_HPP 1

#include <cassert>
#include <vector>

namespace cp {

// op need not be commutative
template <class T, T (*op)(T, T), T (*e)()>
struct segtree {
  int n;
  std::vector<T> data;

  segtree() : n(0) {}
  segtree(int n) : n(n), data(2*n) {}

  void act(int i, T v) {
    for (data[i += n] += v; i > 1; i >>= 1)
      data[i>>1] = op(data[i], data[i^1]);
  }

  T product(int l, int r) {
    T resl = e(), resr = e();
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
      if (l&1)  resl = op(resl, data[l++]);
      if (r&1)  resr = op(data[--r], resr);
    }
    return op(resl, resr);
  }
};

}  // namespace cp

#endif  // COMPROG_SEGTREE_HPP
