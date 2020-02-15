#include <iostream>
#include <vector>
#include <cmath>

using ull = unsigned long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ull> a(N);
  rep(i, N) std::cin >> a[i];
  std::vector<std::vector<ull>> dp(N, std::vector<ull>(N, 0));
  for (auto i = 1;i < N;++i) { //i==1
    dp[i-1][i] = a[i-1] + a[i];
  }
  for (auto i = 0;i < N;++i) {
    for (auto j = 2;j < N;++j)
      if (i+2 >= N) {
        dp[i][i+j] = dp[i][i+j-1]+dp[i][i+j-2];
      } else {
//        dp[i][i+j] = std::min(dp[i][i+j-1]+dp[i][i+j-2], dp[i+1][i+j]+dp[i+2][i+j]);
      }
  }
  std::cout << dp[0][N-1] << '\n';
}
