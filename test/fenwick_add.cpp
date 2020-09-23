#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <comprog/datastruct/fenwick>

int op(int a, int b) { return a + b; }
int op_inv(int a, int b) { return a - b; }
int e() { return 0; }

int main() {
  std::srand(std::time(NULL));

  int N = 10000;
  int ar[N];
  for (int i = 0; i < N; ++i)
    ar[i] = (rand() << 16) ^ rand();

  auto curr_time = time(NULL);

  cp::fenwick<int, op, op_inv, e> fen(N);
  for (int i = 0; i < N; ++i)
    fen.act(i, ar[i]);

  std::cout << time(NULL) - curr_time << "secs \n";

  for (int i = 0; i < N; ++i) {
    int ans = 0;
    for (int j = i; j < N; ++j) {
      ans += ar[j];
      assert(fen.product(i, j) == ans);
    }
  }

  std::cout << time(NULL) - curr_time << "secs \n";
  std::cout << "Fenwick Test A done. All clear!\n";

  return 0;
}
