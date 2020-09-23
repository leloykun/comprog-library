#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <limits>
#include <comprog/datastruct/fenwick>

const int INF = 1e9;

int op(int a, int b) { return std::max(a, b); }
// will not be used:
int op_inv(int a, int b) { return std::max(a, b); }
int e() { return std::numeric_limits<int>::min(); }

int main() {
  std::srand(std::time(NULL));

  int N = 1000000;
  int ar[N];
  for (int i = 0; i < N; ++i)
    ar[i] = (rand() << 16) ^ rand();

  auto curr_time = time(NULL);

  cp::fenwick<int, op, op_inv, e> fen(N);
  for (int i = 0; i < N; ++i)
    fen.act(i, ar[i]);

  std::cout << time(NULL) - curr_time << "secs \n";

  int ans = e();
  for (int j = 0; j < N; ++j) {
    ans = op(ans, ar[j]);
    assert(fen.product(j) == ans);
  }

  std::cout << time(NULL) - curr_time << "secs \n";
  std::cout << "Fenwick Test B done. All clear!\n";

  return 0;
}
