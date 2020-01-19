#include <iostream>
#include <vector>

constexpr int max(int a, int b) {
  return (a>b)?a:b;
}
int main(int argc, char** argv) {
  int a, b;
  std::cin >> a >> b;
  int t_max = max(a, b);
  int t_min = (a+b)-t_max;
  for (auto i = 0;i < t_max;++i) {
    std::cout << t_min;
  }
  std::cout << '\n';
}
