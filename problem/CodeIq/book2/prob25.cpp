#include <iostream>
#include <vector>

namespace prob25{
  const unsigned N {39};
  unsigned long catalan(const unsigned& n, std::vector<unsigned>& memo) {
    if (n < 0) return 0;
    if (memo[n]) return memo[n];
    unsigned long sum {};
    for (auto i = 0;i < n;++i) {
      sum += catalan(i, memo) * catalan(n - 1 - i, memo);
    }
    return memo[n] = sum;
  }
  unsigned long answer() {
    if (N % 2 == 0) {
      return 0;
    } else {
      std::vector<unsigned> memo(N+1);
      memo[0] = 1;
      return catalan((N - 1)/2, memo);
    }
  }
}

int main(int argc, char** argv) {
  std::cout << prob25::answer() << '\n';
}
