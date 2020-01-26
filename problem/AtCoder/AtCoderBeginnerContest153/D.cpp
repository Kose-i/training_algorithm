#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  unsigned long long H;
  std::cin >> H;
  // 2^(N) <= H < 2^(N+1)
  int N {};
  for (unsigned long long i = 1;i < H;++i, ++N) {
    i <<= 1;
  }
  std::vector<unsigned long long> dp(1000000, 0); // random 100
  dp[0] = 1;
  for (auto i = 1;i <= N;++i) {
    dp[i] = 2*dp[i-1]+1;
  }
  std::cout << dp[N] << '\n';
}
