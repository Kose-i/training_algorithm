#include <iostream>
#include <vector>

namespace prob57{
  unsigned long nCr(const int& n, const int& r, std::vector<std::vector<unsigned long>>& memo) {
    if (memo[n][r]) return memo[n][r];
    if ((r==0)||(r==n)) return 1;
    return memo[n][r] = nCr(n-1, r-1, memo)+nCr(n-1, r, memo);
  }
  unsigned long answer(const int& n, const int& a, const int& b) {
    std::vector<std::vector<unsigned long>> memo(n+1, std::vector<unsigned long>(n+1, 0));
    return nCr(n - 2, a-2, memo)*nCr(a-2, b-2, memo);
  }
}

int main(int argc, char** argv) {
  const int n {32};
  const int a {12};
  const int b {4};
  std::cout << prob57::answer(n, a, b) << '\n';
}
