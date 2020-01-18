#include <iostream>
#include <vector>

constexpr int max(int a, int b) {
  return (a>b)?a:b;
}

int main(int argc, char** argv) {
  int H, W, N;
  std::cin >> H >> W >> N;
  int max_HW = max(H, W);
  if (N % max_HW) std::cout << (N/max_HW + 1) << '\n';
  else std::cout << (N/max_HW) << '\n';
}
