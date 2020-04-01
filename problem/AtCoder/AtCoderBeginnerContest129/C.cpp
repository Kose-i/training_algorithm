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
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

constexpr ull mod_p {1000000007};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  rep(i, M) cin >> a[i];

  vector<ull> dp(N+1, 0);
  dp[0] = 1;
  int c {};
  if (a[c] == 1) {
    dp[1] = 0;
    ++c;
  } else {
    dp[1] = 1;
  }

  srep(i, 2, N+1) {
    if (c < M && a[c] == i) {
      dp[i] = 0;
      ++c;
    } else {
      dp[i] = dp[i-1] + dp[i-2];
      dp[i] %= mod_p;
    }
  }
  cout << dp[N] << '\n';
}
