#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
  unsigned long N;
  std::cin >> N;
  unsigned long x = std::sqrt(N);
  for (;;--x) {
    if (N % x == 0) break;
  }
  std::cout << (N/x + x - 2) << '\n';
}
