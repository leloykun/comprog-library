#include <comprog/datastruct/monoid>
#include <comprog/datastruct/group>
#include <iostream>

int add(int x, int y) {
  return x + y;
}

int invert(int x) {
  return -x;
}

int main() {
  cp::monoid<int> M{0, add};
  cp::group<int>  G{0, add, invert};

  cp::monoid<int> ML{0, [](int x, int y) {return x+y;}};
  cp::group<int>  GL{0, [](int x, int y) {return x+y;}, [](int x) {return -x;}};

  std::cout << "Monoid:\n";
  std::cout << M.id << "\n";
  std::cout << M.op(3, 5) << "\n";
  std::cout << "Group:\n";
  std::cout << G.id << "\n";
  std::cout << G.op(3, 5) << "\n";
  std::cout << G.op(3, G.inv(5)) << "\n";
  std::cout << "Monoid Lambda:\n";
  std::cout << ML.id << "\n";
  std::cout << ML.op(3, 5) << "\n";
  std::cout << "Group Lambda:\n";
  std::cout << GL.id << "\n";
  std::cout << GL.op(3, 5) << "\n";
  std::cout << GL.op(3, GL.inv(5)) << "\n";

  return 0;
}
