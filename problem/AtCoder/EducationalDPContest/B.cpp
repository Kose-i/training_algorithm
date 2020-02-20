#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using ll = long long;

#define rep(i, n) for(int i=0;i<(n);++i)
#define chmin(x,y) x=std::min(x,y)

constexpr ll INF {1000000000000};

int main(int argc, char** argv) {
  ll N, K;
  std::cin >> N >> K;
  std::vector<ll> H(N);
  rep(i,N) std::cin >> H[i];
  std::vector<ll> dp(N, INF);
  dp[0] = 0;

  rep(i, N) {
    for (auto j = 1;j <= K;++j) {
      ll p = i+j;
      if (p >= N) break;
      chmin(dp[p], dp[i]+std::abs(H[i]-H[p]));
    }
  }
  std::cout << dp[N-1] << '\n';
}
