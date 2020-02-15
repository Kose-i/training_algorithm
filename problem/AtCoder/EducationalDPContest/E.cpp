#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ull = unsigned long long;
struct Product {
  ull w, v;
};
//bool operator<(const Product& l, const Product& r) {
//  l.v > r.v;
//}

int main(int argc, char** argv) {
  ull N, W;
  std::cin >> N >> W;
  std::vector<Product> P(N);
  for (auto i = 0;i < N;++i) std::cin >> P[i].w >> P[i].v;

  ull max_value {};
  for (auto i = 0;i < N;++i) max_value += P[i].v;

  std::vector<std::vector<ull>> dp(N, std::vector<ull>(max_value+1, W+1));
  dp[0][0] = 0;
  dp[0][P[0].v] = P[0].w;
  for (auto i = 1;i < N;++i) {
    for (auto j = 0;j <= max_value;++j) {
      dp[i][j] = dp[i-1][j];
    }
    for (auto j = 0;j <= max_value;++j) {
      if (j + P[i].v > max_value) break;
      dp[i][j+P[i].v] = std::min(dp[i-1][j+P[i].v], dp[i-1][j] + P[i].w);
    }
  }
  ull answer {};
//  for (const auto& e : dp) {
//    for (const auto& f : e) {
//      std::cout << f << ' ';
//    }
//    std::cout << '\n';
//  }
  for (auto i = 0;i <= max_value;++i) {
    if (dp[N-1][i] <= W) answer = i;
  }
  std::cout << answer << '\n';
}
