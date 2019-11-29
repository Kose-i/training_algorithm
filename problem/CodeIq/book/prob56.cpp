#include <iostream>

namespace prob56{
  unsigned answer(const int& m, const int& n) {
    if (n == 1) return 3;
    unsigned cnt = (3+(m-1)*(m-2)/2) * answer(m, n-1);
    for (auto i = 2;i < m;++i) {
      cnt += 3 * answer(i, n-1);
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  const int m {10};
  const int n {6};
  std::cout << prob56::answer(m, n) << '\n';
}
