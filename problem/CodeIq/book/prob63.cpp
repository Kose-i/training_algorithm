#include <iostream>

namespace prob63{
  unsigned gcd(const int& a, const int& b) {
    if (b == 0) return a;
    return gcd(b, a%b);
  }
  unsigned lcm(const int& a, const int& b) {
    return a*b/gcd(a,b);
  }
  void answer(const int& M, const int& N) {
    if (M==N) {
      std::cout << M << '\n';
      std::cout << 2*M << '\n';
    } else if (gcd(M, N) == 1) {
      std::cout << M*N << '\n';
      std::cout << M*N << '\n';
    } else {
      unsigned temp = lcm(M, N);
      std::cout << temp << '\n';
      std::cout << 2*temp << '\n';
    }
  }
}

int main(int argc, char** argv) {
  const int m {60};
  const int n {60};
  prob63::answer(m, n);
}
