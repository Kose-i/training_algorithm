#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
  // unsigned long ans = std::pow(2, 15) + std::pow(2, 12) - 1;
  unsigned long ans = (1<<(15)) + (1<<(12)) - 1;
  std::cout << ans << '\n';
}
