#include <iostream>
#include <vector>

int main(int argc, char** argv) {

  int ans {};
  constexpr int n {10};
  std::vector<int> dp(n+1, 0);
  dp[0] = 1;//initial

  for (auto i = 0;i < n;++i) {
    std::vector<int> dp_cp(n+1, 0);
    for (auto j = 0;j < n;++j) {
      for (auto step = 1;step <= 4;++step) {
        dp_cp[j+step] += dp[j];
      }
    }
    dp = dp_cp;
    for (auto j = 0;j < n;++j) {
      ans += dp[j]*dp[n-j];
    }
  }
  std::cout << ans << '\n';
}
