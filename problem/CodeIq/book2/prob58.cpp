#include <cmath>
#include <iostream>
#include <vector>

namespace prob58{
  unsigned long catalan(const int& n, std::vector<unsigned long>& memo) {
    if (memo[n]) return memo[n];
    if (n == 0) return 1;
    unsigned long sum {};
    for (auto i = 0;i < n;++i) {
      sum += catalan(i, memo) * catalan(n-i-1, memo);
    }
    return memo[n] = sum;
  }
  unsigned long answer(const int& N) {
    if (N > 2) {
      std::vector<unsigned long> memo(N, 0);
      return catalan(N-1, memo)*(N-2)*std::pow(2, N-3);
    } else {
      return 0;
    }
  }
}

int main(int argc, char** argv) {
  const int n {15};
  std::cout << prob58::answer(n) << '\n';
}
