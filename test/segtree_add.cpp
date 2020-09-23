#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <chrono>
#include <vector>
#include <comprog/datastruct/segtree>
#include <comprog/datastruct/segtree_iter>
#include <comprog/datastruct/segtree_vern>

double get_time_elapsed(std::chrono::high_resolution_clock::time_point &start_time) {
  auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
  return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() / 1000.0;
}

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
  std::srand(std::time(NULL));

  int N = 10000;
  std::vector<int> ar(N);
  for (int i = 0; i < N; ++i)
    ar[i] = (rand() << 16) ^ rand();

  std::cout << "Iterative segtree:\n";
  std::cout << "Building: \n";
  auto start_time = std::chrono::high_resolution_clock::now();
  cp::segtree_iter<int, op, e> root1(N);
  for (int i = 0; i < N; ++i) root1.act(i, ar[i]);
  std::cout << get_time_elapsed(start_time) << "secs \n";
  std::cout << "Main Test Loop: \n";
  start_time = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) {
    int ans = 0;
    for (int j = i; j < N; ++j) {
      ans = op(ans, ar[j]);
      assert(root1.product(i, j) == ans);
    }
  }
  std::cout << get_time_elapsed(start_time) << "secs \n";
  std::cout << "---\n";

  std::cout << "Recursive segtree:\n";
  std::cout << "Building: \n";
  start_time = std::chrono::high_resolution_clock::now();
  cp::segtree<int, op, e> root2(ar, 0, N-1);
  std::cout << get_time_elapsed(start_time) << "secs \n";
  std::cout << "Main Test Loop: \n";
  start_time = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) {
    int ans = 0;
    for (int j = i; j < N; ++j) {
      ans = op(ans, ar[j]);
      assert(root2.product(i, j) == ans);
    }
  }
  std::cout << get_time_elapsed(start_time) << "secs \n";
  std::cout << "---\n";

  std::cout << "Vernon segtree:\n";
  std::cout << "Building: \n";
  start_time = std::chrono::high_resolution_clock::now();
  segtree_vern<int> root3(N, {0, [](const int& x, const int& y){return x+y;}});
  for (int i = 0; i < N; ++i) root3.update(i, ar[i]);
  std::cout << get_time_elapsed(start_time) << "secs \n";
  std::cout << "Main Test Loop: \n";
  start_time = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) {
    int ans = 0;
    for (int j = i; j < N; ++j) {
      ans = op(ans, ar[j]);
      assert(root3.query(i, j, true) == ans);
    }
  }
  std::cout << get_time_elapsed(start_time) << "secs \n";
  std::cout << "---\n";


  std::cout << "Segtree Test ADD done. All clear!\n";

  return 0;
}
