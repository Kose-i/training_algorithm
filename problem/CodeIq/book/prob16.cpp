#include <iostream>

namespace prob16{
  const unsigned Sum{1234567};
  unsigned Euclidean(unsigned a, unsigned b){
    unsigned c = a % b;
    while (c > 0) {
      a = b;
      b = c;
      c = a % b;
    }
    return b;
  }
  unsigned answer() {
    unsigned cnt {};
    for (auto i = 1;i < (Sum+1)/2;++i) {
      if (Euclidean(i, Sum - i)==1)cnt += 1;
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  std::cout << prob16::answer() << '\n';
}
