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

constexpr ll ll_mod {998244353};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, d;
  cin >> n >> d;
  vector<ll> two(n+1, 0);
  two[0] = 1;
  for (int i=1;i<=n;++i) two[i] = (two[i-1]*2) % ll_mod;

  ll ans {};
  for (int i=0;i<=d;++i) {
    int l = i;
    int r = d - l;
    if (n <= l) continue;
    if (n <= r) continue;

    ans += ((two[max(l-1, 0)]*two[max(r-1, 0)])%ll_mod)*(two[n-max(l,r)] - 1) % ll_mod;
    ans %= ll_mod;
  }
  ans *= 2;
  ans %= ll_mod;
  cout << ans << '\n';
}
