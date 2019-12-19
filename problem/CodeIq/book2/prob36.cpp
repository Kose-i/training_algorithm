#include <iostream>
#include <cmath>

namespace prob36{
  unsigned long check(const int& n) {
    if (n <= 1) return n;
    return 7*check(n-2) + 3*std::pow(7, n-1);
  }
  unsigned long answer(const int& size) {
    return check(size);
  }
}

int main(int argc, char** argv) {
  const int size {12};
  std::cout << prob36::answer(size) << '\n';
}
