#include <iostream>
#include <vector>
#include <numeric>

#include <iomanip>

using ll = long long;
constexpr ll INF {100000000};

#define rep(i,n) for(int i = 0;i < (n);++i)

ll answer(const int& l, const int& r, std::vector<std::vector<ll>>& dp, const std::vector<ll>& A) {
  if (dp[l][r] >= 0) return dp[l][r];
  dp[l][r] = INF;
  ll sum_cost = std::accumulate(A.begin()+l, A.begin()+r, 0);
  for (auto i = l+1;i < r-1;++i) {
    //dp[l][r] = std::min(dp[l][r], dp[l][i]+dp[i+1][r]+sum_cost);
    dp[l][r] = std::min(dp[l][r], answer(l,i,dp,A)+answer(i+1,r,dp,A)+sum_cost);
  }
  return dp[l][r];
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ll> A(N);
  rep(i,N) std::cin >> A[i];
  std::vector<std::vector<ll>> dp(N+1, std::vector<ll>(N+1, -1));
  rep(i,N+1) dp[i][i] = 0;
  std::cout << answer(1, N, dp, A) << '\n';
  for (const auto& e : dp) {
    for (const auto& f : e) {
      std::cout << std::setw(10) << std::setfill(' ') << f << ' ';
    }
    std::cout << '\n';
  }
}
