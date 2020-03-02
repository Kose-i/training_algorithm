#include <iostream>
#include <vector>

//#include <iomanip>

using ll = unsigned long long;
#define rep(i,n) for(int i = 0;i < (n);++i)
#define drep(i,n) for(int i = (n)-1;i >= 0;--i)
#define srep(i,s,t) for(int i = s;i < t;++i)

constexpr ll INF = 1001002003004005006ll;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i,n) std::cin >> a[i];
  std::vector<ll> s(n+1);
  s[0] = 0;
  rep(i,n) s[i+1] = a[i]+s[i];

  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n,INF));
  drep(l,n) srep(r, l, n) {
    if (l == r) dp[l][r] = 0;
    else {
      srep(k,l,r) {
        dp[l][r] = std::min(dp[l][r], dp[l][k]+dp[k+1][r]+(s[r+1]-s[l]));
      }
    }
  }
  std::cout << dp[0][n-1] << '\n';
}
