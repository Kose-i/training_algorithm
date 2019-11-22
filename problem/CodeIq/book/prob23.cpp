#include <iostream>
#include <vector>

namespace prob23{
  const unsigned size {100};
  unsigned splits(const int& n, std::vector<unsigned>& memo) {
    if (n < 0) return 0;
    if (memo[n]) return memo[n];
    unsigned result {0};
    if (n < 6) result += 1;
    for (auto i = 2; i <= 5;++i) {
      if (n - i*2 > 1) result += splits(n - i*2, memo);
      if (n - i*2 == 0) result += 1;
    }
    return memo[n] = result;
  }
  unsigned answer() {
    std::vector<unsigned> memo(size*size, 0);
    unsigned cnt {};
    for (auto i = 2;i < size;++i) {
      if (size % i == 0) {
        cnt += splits(i, memo);
      }
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  std::cout << prob23::answer() << '\n';
}
