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

  int a, b, x, y;
  cin >> a >> b >> x >> y;

  int n {};
  if (a <= b) {
    n = b - a + 1;
  } else {
    n = a - b + 1;
  }

  std::vector<std::vector<int>> dp(2, std::vector<int>(n, -1));
  dp[0][0] = 0;
  dp[1][0] = x;
  for (int i = 1;i < n;++i) {
    dp[0][i] = dp[0][i-1] + y;
    dp[1][i] = dp[1][i-1] + y;
    if (a <= b) mins(dp[0][i], dp[1][i-1]+x);
    else mins(dp[1][i], dp[0][i-1] + x);
    mins(dp[1][i], dp[0][i] + x);
    mins(dp[0][i], dp[1][i] + x);
  }
  cout << dp[1][n-1] << '\n';
}
