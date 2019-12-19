#include <iostream>

namespace prob8{
  unsigned nCr(const unsigned& n, const unsigned& r) {
    unsigned t{1};
    for (auto i = 0;i < r;++i) {
      t *= (n - i);
    }
    for (auto i = r;0 < i;--i) {
      t /= i;
    }
    return t;
  }
  unsigned answer() {
    return nCr(9, 1)*2 + 1;
  }
}
int main(int argc, char** argv) {
  std::cout << prob8::answer() << '\n';
}
