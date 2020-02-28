#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
#define rep(i, n) for(int i = 0;i < (n);++i)

constexpr ll mod {1000000007};
constexpr ll INF {-1};

ll answer(const ll& N, const ll& K, const std::vector<ll>& a) {
  std::vector<std::vector<ll>> dp(N+1, std::vector<ll>(K+1, 0));
  dp[0][0] = 1;
  for (auto i = 0;i < N;++i) {
    std::vector<ll> sum(K+2, 0);
    for (auto j = 0;j <= K;++j) {
      (sum[j+1] = (sum[j]+dp[i][j])) %= mod;
    }
    for (auto j = 0;j <= K;++j) {
      (sum[j+1] = (sum[j]+dp[i][j])) %= mod;
      (dp[i+1][j] = (sum[j+1] - sum[std::max(j-a[i], 0LL)] + mod)) %= mod;
    }
  }
  return dp[N][K];
}

int main(int argc, char** argv) {
  ll N, K;
  std::cin >> N >> K;
  std::vector<ll> a(N);
  rep(i, N) std::cin >> a[i];
  std::cout << answer(N, K, a) << '\n';
}
