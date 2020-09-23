#ifndef COMPROG_SEGTREE_HPP
#define COMPROG_SEGTREE_HPP 1

#include <cassert>
#include <vector>

namespace cp {

// op need not be commutative
template <class T, T (*op)(T, T), T (*e)()>
struct segtree {
  int i, j;
  T val;
  segtree *l, *r;
  segtree(int _i, int _j) : i(_i), j(_j) {
    if (i == j) {
      val = e();
      l = r = NULL;
    } else {
      int k = (i+j) >> 1;
      l = new segtree(i, k);
      r = new segtree(k+1, j);
      val = op(l->val, r->val);
    }
  }
  segtree(std::vector<T> &ar, int _i, int _j) : i(_i), j(_j) {
    if (i == j) {
      val = ar[i];
      l = r = NULL;
    } else {
      int k = (i+j) >> 1;
      l = new segtree(ar, i, k);
      r = new segtree(ar, k+1, j);
      val = op(l->val, r->val);
    }
  }
  void act(int _i, T delta) {
    if (_i <= i and j <= _i) {
      val = op(val, delta);
    } else if (_i < i or j < _i) {
      // do nothing
    } else {
      l->act(_i, delta);
      r->act(_i, delta);
      val = op(l->val, r->val);
    }
  }
  T product(int _i, int _j) {
    if (_i <= i and j <= _j) {
      return val;
    } else if (_j < i or j < _i) {
      return e();
    } else {
      return op(l->product(_i, _j), r->product(_i, _j));
    }
  }
};

}  // namespace cp

#endif  // COMPROG_SEGTREE_HPP
