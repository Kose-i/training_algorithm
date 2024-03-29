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
  vector<ll> f(n+1, 0);
  vector<ll> g(n+1, 0);
  vector<ll> two(n+1, 0);
  two[0] = 1;
  for (int i=1;i<=n;++i) two[i] = (two[i-1]*2) % ll_mod;
  for (int i=1;i<=n;++i) {
    int l = i - 1;
    int r = d-(i-1);
    if (0<= r && r<=l) g[i] = (g[i-1] + two[max(l-1, 0)] * two[max(r-1, 0)] * ((l!=r)?2:1)) % ll_mod;
    else g[i] = g[i-1];
  }

  for (int i=1;i<=n;++i) f[i] = (2*f[i-1] + g[i]) % ll_mod;
  cout << (f[n]*2)%ll_mod << '\n';
}
