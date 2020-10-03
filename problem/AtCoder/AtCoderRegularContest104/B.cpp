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
struct idensi {
  int cnt_a, cnt_t, cnt_c, cnt_g;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::string s;
  cin >> n >> s;

  std::vector<idensi> dp(n+1);
  dp[0].cnt_a = 0; dp[0].cnt_g = 0;
  dp[0].cnt_t = 0; dp[0].cnt_c = 0;
  rep(i,n) {
    dp[i+1] = dp[i];
    if (s[i] == 'A') {
      ++dp[i+1].cnt_a;
    } else if (s[i] == 'G') {
      ++dp[i+1].cnt_g;
    } else if (s[i] == 'C') {
      ++dp[i+1].cnt_c;
    } else {
      ++dp[i+1].cnt_t;
    }
  }

  //for (const auto& e : dp) {
  //  cout << e.cnt_a << ' ' << e.cnt_g << ' ' << e.cnt_c << ' ' << e.cnt_t << '\n';
  //}

  int ans {};

  for (auto i = 0;i < n+1;++i) {
    for (auto j = i+1;j < n+1;++j) {
      if (dp[j].cnt_a - dp[i].cnt_a == dp[j].cnt_t - dp[i].cnt_t && \
          dp[j].cnt_g - dp[i].cnt_g == dp[j].cnt_c - dp[i].cnt_c ) {
        ++ans;
      }
      //std::cout << i << ' ' << j << '\n';
    }
  }
  cout << ans << '\n';
}
