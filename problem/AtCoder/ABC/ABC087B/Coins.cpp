#include <iostream>

namespace coins_answer{
  unsigned answer(const int& A, const int& B, const int& C, const unsigned& X) {
    unsigned minimum_500s = X / 500;
    unsigned minimum_100s = X / 100 - 5*minimum_500s;
    unsigned minimum_50s  = (X % 100 )/ 50;
    if (A < minimum_500s) {
      minimum_100s += 5*(minimum_500s - A);
      minimum_500s = A;
    }
    if (B < minimum_100s) {
      minimum_50s += 2*(minimum_100s - B);
      minimum_100s = B;
    }
    if (C < minimum_50s) {
      return 0;
    }
    unsigned count {};
    for (auto t = 0; t <= minimum_500s ;++t) {
      for (auto s = 0; s <= minimum_100s + 5*minimum_500s - 5*t && s <= B; ++s) {
        if (C < minimum_50s + 10*minimum_500s - 10*t + 2*minimum_100s - 2*s) {
          continue;
        } else {
          ++count;
        }
      }
    }
    return count;
  }
}

int main(int argc, char** argv) {
  const int A {[](){int t;std::cin >> t;return t;}()};
  const int B {[](){int t;std::cin >> t;return t;}()};
  const int C {[](){int t;std::cin >> t;return t;}()};
  const unsigned X {[](){unsigned t;std::cin >> t;return t;}()};
  std::cout << coins_answer::answer(A, B, C, X) << '\n';
}
