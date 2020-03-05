#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define chmin(x,y) x=std::min(x,y)

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)
constexpr ll INF {100000000};

int main(int argc, char** argv) {
  std::string S;
  std::cin >> S;
  std::reverse(S.begin(), S.end());
  S += '0';
  ll S_size = S.size();
  std::vector<std::vector<ll>> dp(S_size, std::vector<ll>(2, INF));
  dp[0][0] = S[0] - '0' ;
  dp[0][1] = 10 - (S[0] - '0');
  for (auto i = 1;i < S_size;++i) {
    ll x = S[i] - '0';
    for (auto j = 0;j < 2;++j) {
      x += j;
      chmin(dp[i][0],dp[i-1][j]+x);
      chmin(dp[i][1],dp[i-1][j]+(10-x));
    }
  }
  std::cout << dp[S_size-1][0] << '\n';
}
