#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int n {30};
  std::vector<std::vector<int>> dp(2, std::vector<int>(n+1, 0));
  dp[0][1] = dp[1][1] = 1;
  for (auto i = 2;i <= n;++i) {
    dp[0][i] = dp[0][i-1] + dp[1][i-1]; //right is boy
    dp[1][i] = dp[0][i-1];
  }
  std::cout << dp[0][n] + dp[1][n] << '\n';
}
