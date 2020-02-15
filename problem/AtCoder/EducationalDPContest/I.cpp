#include <iostream>
#include <vector>
#include <stdio.h>

#define rep(i, n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<double> p(N);
  rep(i, N) std::cin >> p[i];
  std::vector<std::vector<double>> dp(N+1, std::vector<double>(N+1, 0));
  dp[0][0] = 1;
  for (auto i = 1;i <= N;++i) {
    for (auto j = 0;j <= i;++j) { // 表の数
      dp[i][j+1] += dp[i-1][j]*p[i-1];
      dp[i][j]   += dp[i-1][j]*(1.00 - p[i-1]);
    }
  }

  double answer {};
  for (auto i = (N+1)/2;i <= N;++i) {
    answer += dp[N][i];
  }

//  std::cout << std::fixed << answer << '\n';
  printf("%.10f\n", answer);
}
