#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;
struct Product {
  ll w, v;
};
//bool operator<(const Product& l, const Product& r) {
//  l.v > r.v;
//}

int main(int argc, char** argv) {
  ll N, W;
  std::cin >> N >> W;
  std::vector<Product> P(N);
  for (auto i = 0;i < N;++i) std::cin >> P[i].w >> P[i].v;
  std::vector<std::vector<ll>> dp(N, std::vector<ll>(W+1, 0));

  if (P[0].w <= W) dp[0][P[0].w] = P[0].v;
  for (auto i = 1;i < N;++i) {
    for (auto j = 0;j <= W;++j) {
      dp[i][j] = dp[i-1][j];
    }
    for (ll j = 0;j < W;++j) {
      if (j + P[i].w <= W) dp[i][j+P[i].w] = std::max(dp[i][j+P[i].w], dp[i-1][j] + P[i].v);
    }
  }

  ll max_value {};
  for (auto i = 0;i <= W;++i) {
    max_value = std::max(max_value, dp[N-1][i]);
  }
  std::cout << max_value << '\n';
}
