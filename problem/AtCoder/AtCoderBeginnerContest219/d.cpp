#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = std::pair<int, int>;

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

  int n, x, y;
  cin >> n >> x >> y;
  vector<Pair> a(n);
  for (int i=0;i<n;++i) cin >> a[i].first >> a[i].second;
  vector<vector<int>> dp(y+1, vector<int>(x+1, INTINF));
  dp[0][0] = 0;
  for (int i=0;i<n;++i) {
    for (int j=y;0<=j;--j) {
      for (int k=x;0<=k;--k) {
        mins(dp[min(y, j+a[i].second)][min(x, k+a[i].first)],dp[j][k] + 1);
      }
    }
  }
  if (dp[y][x] > n) cout << "-1\n";
  else cout << dp[y][x] << '\n';
}
