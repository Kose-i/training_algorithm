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

constexpr ll target_mod {998244353};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> h(n+1, 0);
  rep(i, k) {
    int left, right;
    cin >> left >> right;
    for (auto i = left;i <= right;++i) h[i] = 1;
  }
  vector<int> s;
  rep(i, n) {
    if (h[i]==1)s.push_back(i);
  }

  vector<int> dp(n+1, 0);
  unsigned int boxsize {s.size()};
  dp[1] = 1;
  rep(i, n+1) {
    if (dp[i] != 0) {
      for (auto j = 0;j < boxsize;++j) {
        if (i+s[j]>n) break;
        dp[i+s[j]] += dp[i];
        dp[i+s[j]] %= target_mod;
      }
    }
  }
  cout << dp[n] << '\n';
}
