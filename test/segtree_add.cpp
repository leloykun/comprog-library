#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <comprog/datastruct/segtree>

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
  std::srand(std::time(NULL));

  int N = 10000;
  int ar[N];
  for (int i = 0; i < N; ++i)
    ar[i] = (rand() << 16) ^ rand();

  cp::segtree<int, op, e> root(N);
  for (int i = 0; i < N; ++i)
    root.act(i, ar[i]);

  for (int i = 0; i < N; ++i) {
    int ans = 0;
    for (int j = i; j < N; ++j) {
      ans += ar[j];
      assert(root.product(i, j) == ans);
    }
  }

  std::cout << "Segtree Test A done. All clear!\n";

  return 0;
}
