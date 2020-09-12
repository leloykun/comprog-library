#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <comprog/datastruct/fenwick>

const int INF = 1e9;

int op(int a, int b) { return std::max(a, b); }
// will not be used:
int invert(int a) { return a; }
int e() { return -INF; }

int main() {
  std::srand(std::time(NULL));

  int N = 10000;
  int ar[N];
  for (int i = 0; i < N; ++i)
    ar[i] = (rand() << 16) ^ rand();

  cp::fenwick<int, op, invert, e> fen(N);
  for (int i = 0; i < N; ++i)
    fen.act(i, ar[i]);

  int ans = e();
  for (int j = 0; j < N; ++j) {
    ans = op(ans, ar[j]);
    //std::cout << ans << " " << fen.sum(j) << "\n";
    assert(fen.product(0, j) == ans);
  }

  std::cout << "Fenwick Test B done. All clear!\n";

  return 0;
}
