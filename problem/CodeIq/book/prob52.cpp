#include <cmath>
#include <iostream>

namespace prob52{
  unsigned answer(const int& N) {
    unsigned max {};
    for (auto i = 1;i <= N; ++i) {
      unsigned tmp = std::pow(i, N-i);
      max = (max > tmp)?max:tmp;
    }
    return max;
  }
}

int main(int argc, char** argv) {
  const int N {16};
  std::cout << prob52::answer(N) << '\n';
}
