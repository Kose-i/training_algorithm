#include <iostream>
#include <cmath>

namespace prob44{
  unsigned trit(const int& n) {
    if (n == 0) return 1;
    unsigned a {};
    while (std::pow(3, a+1) <= n) {
      ++a;
    }
    unsigned min_trit_target = (n - std::pow(3, a), std::pow(3, a) - 1);
    return (std::pow(2, a) + trit(min_trit_target));
  }
  unsigned answer(const int& N) {
    return trit(N);
  }
}

int main(int argc, char** argv) {
  const int max_n {12345};
  std::cout << prob44::answer(max_n) << '\n';
}
