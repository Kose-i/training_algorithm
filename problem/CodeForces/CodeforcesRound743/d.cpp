#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <utility>

using Pair = std::pair<int,int>;

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

  int n, x, y;
  cin >> n >> x >> y;
  vector<Pair> a(n);
  rep(i, n) cin >> a[i].first >> a[i].second;

  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, n+1)));
  dp[0][0][0] = 0;

  for (int i = 1;i <= n;++i) {
    for (int j=0;j<=x;++j) {
      for (int k = 0;k <= y;++k) {
        mins(dp[i][min(x, j+a[i].first)][min(y, k+a[i].second)], dp[i-1][j][k]+1);
      }
    }
  }
  if (dp[n][x][y] > n) {
    cout << "-1\n";
  } else {
    cout << dp[n][x][y] << '\n';
  }
}
