#include <iostream>

int cut(const int& n, const int& m, int t) {
  //std::cout << n << ' ' << m << ' ' << t << '\n';
  if (n <= t) return 0;
  if (t <= m) return 1+cut(n, m, t*2);
  return 1+cut(n, m, t+m);
}

int main(int argc, char** argv) {
  int n {8};
  int m {3};

  std::cout << cut(n, m, 1) << '\n';
  std::cout << cut(20, 3, 1) << '\n';
  std::cout << cut(100, 5, 1) << '\n';
}
