#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INTINF {1000000000};//int = 2*INTINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T&& y) {
  x=std::max(x,y);
}
template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T&& y) {
  x=std::min(x,y);
}
template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  constexpr ll mod_target {998244353};

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i=0;i<n;++i) cin >> a[i];
  for (int i=0;i<n;++i) cin >> b[i];

  vector<vector<ll>> dp(n, vector<ll>(b[n-1]+1, 0));
  // i==n-1
  for (int j= b[n-1];a[n-1] <= j;--j) dp[n-1][j] = 1;
  for (int i=n-2;0 <= i;--i) {
    //j == b[i]
    for (int j=b[i];j<=b[i+1];++j) {
        dp[i][b[i]] += dp[i+1][j];
        dp[i][b[i]] %= mod_target;
    }
    for (int j = b[i]-1;a[i] <= j;--j) {
        dp[i][j] = dp[i][j+1] + dp[i+1][j];
        dp[i][j] %= mod_target;
    }
  }

  ll ans {};
  for (int i=a[0];i<=b[0];++i) {
    ans += dp[0][i];
    ans %= mod_target;
  }
  cout << ans << '\n';

}
