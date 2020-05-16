#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

  string S;
  cin >> S;
  int n = S.size();
  vector<int> dp(n);
  rep(i,n) {
    if (i==0) dp[i] = S[0] - '0';
    else dp[i] = (dp[i-1]*10+(S[i]-'0')) % 2019;
  }
  rep(i, n) {
    cout << dp[i] << '\n';
  }
  std::unordered_map<int, int> mp;
  mp[0] = 1;
  rep(i,n) {
    ++mp[dp[i]];
  }

  int ans {};
  rep(i, 2020) {
    int m = mp[i];
    ans += (m*(m-1)/2);
  }
  cout << ans << '\n';
}
