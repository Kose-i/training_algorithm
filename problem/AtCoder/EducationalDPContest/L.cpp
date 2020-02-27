#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)
constexpr ll INF {3000000000000};

ll search(int left, int right, std::vector<std::vector<ll>>& dp, const std::vector<ll>& a, bool is_first) {
  if (dp[left][right] != INF && dp[left][right] != -INF) return dp[left][right];
  if (left == right) {
    if (is_first == true) return a[left];
    else return -a[left];
  }
  if (is_first == true) {
    ll c = a[left] + search(left+1, right, dp, a, false);
    dp[left][right] = std::max(dp[left][right], c);
    c    = a[right] + search(left, right-1, dp, a, false);
    dp[left][right] = std::max(dp[left][right], c);
  } else {
    ll c = - a[left] + search(left+1, right, dp, a, true);
    dp[left][right] = std::min(dp[left][right], c);
    c    = - a[right] + search(left, right-1, dp, a, true);
    dp[left][right] = std::min(dp[left][right], c);
  }
  return dp[left][right];
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ll> a(N);
  rep(i,N) std::cin >> a[i];

  std::vector<std::vector<ll>> dp(N+1, std::vector<ll>(N+1, INF));
  rep(i,N+1) {
    rep(j,N+1) {
      if ((N+i+j) % 2 == 1) {
        dp[i][j] = -INF;
      } else {
        dp[i][j] = INF;
      }
    }
  }
  std::cout << search(0, N-1, dp, a, true) << '\n';
}
