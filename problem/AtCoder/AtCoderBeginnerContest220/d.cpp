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
constexpr ll ll_mod {998244353};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0;i<n;++i) cin >> a[i];
  vector<vector<ll>> dp(n, vector<ll>(10, 0));
  dp[0][a[0]] = 1;

  for (int i=1;i<n;++i) {
    for (int j=0;j<10;++j) {
        dp[i][(j+a[i])%10] += dp[i-1][j];
        dp[i][(j*a[i])%10] += dp[i-1][j];
    }
    for (int j=0;j<10;++j) dp[i][j] %= ll_mod;
  }
  for (int i=0;i<10;++i) cout << dp[n-1][i] << '\n';
}
