#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  int K;
  std::cin >> K;
  std::vector<int> A(N);
  for (auto& e : A) std::cin >> e;
  std::vector<std::vector<int>> dp(N+1, std::vector<int>(N+1, 0));

  int cnt {};
  for (auto i = 0;i < N;++i) {
    dp[i][i+1] = A[i]%K;
    if (dp[i][i+1] == 1)++cnt;
  }
  for (auto k = 1;k < N;++k) {
    for (auto i = 0;i < N-k-1;++i) {
      dp[i][i+1+k] = dp[i][i+k] + dp[i+1][i+1+k];
      dp[i][i+1+k] %= K;
      if (dp[i][i+1+k] == k-1) ++cnt;
    }
  }
  for (const auto& e : dp) {
    for (const auto& f : e) {
      std::cout << f << ' ';
    }
    std::cout << '\n';
  }
  std::cout << cnt << '\n';
}
