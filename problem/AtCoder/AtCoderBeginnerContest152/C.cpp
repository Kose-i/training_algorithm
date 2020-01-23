#include <iostream>
#include <vector>

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> P(N);
  for (auto& e : P) std::cin >> e;
  std::vector<int> dp(N, P[0]);
  for (auto i = 1;i < N;++i) {
    dp[i] = min(dp[i-1], P[i]);
  }
  int cnt {};
  for (auto i = 0;i < N;++i) {
    if (P[i] <= dp[i]) ++cnt;
  }
  std::cout << cnt << '\n';
}
