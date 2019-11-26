#include <iostream>

namespace prob32{
  unsigned answer(const int& m, const int& n) {
    int x = 2*m - n;
    if (x > 0) return ((3*m - n)/2) - x +1;
    else       return ((3*m - n)/2) +1;
  }
}

int main(int argc, char** argv) {
  const int m {543210};
  const int n {987654};
  std::cout << prob32::answer(m, n) << '\n';
}
