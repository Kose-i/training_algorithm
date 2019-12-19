#include <iostream>
#include <vector>

namespace prob19{
  const unsigned RUNNER {50};
  const unsigned HOOK {35};
  unsigned nCr(unsigned n, unsigned r, std::vector<std::vector<unsigned>>& memo) {
    if (r == 0 || r == n)return 1;
    if (memo[n][r] != 0) return memo[n][r];

    return memo[n][r] = nCr(n - 1, r - 1, memo) + nCr(n - 1, r, memo);
  }
  unsigned answer() {
    std::vector<std::vector<unsigned>> memo(35 ,std::vector<unsigned>(35, 0));
    return nCr(HOOK-1, RUNNER-HOOK, memo);
  }
}

int main(int argc, char** argv) {
  std::cout << prob19::answer() << '\n';
}
