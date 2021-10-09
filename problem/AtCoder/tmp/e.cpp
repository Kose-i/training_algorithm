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
constexpr ll mod_par {1000000000 + 7};

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

  ll n, m, k;
  cin >> n >> m >> k;

  if (m == 0 && n == 0) {
    cout << 0 << '\n';
    return 0;
  } else if (m == 0 && k < n) {
    cout << 0 << '\n';
    return 0;
  } else if (m == 0) {
    cout << 1 << '\n';
    return 0;
  } else if (n == 0) {
    cout << 1 << '\n';
    return 0;
  }

  ll ans {1};
  for (auto i = 0;i < n+m;++i) {
    ans *= 2;
    ans %= mod_par;
  }
  cout << ans << '\n';
  for (ll i = 1;i <= n;++i) {
    ans -= i*(i+1)/2;
    while (ans <= 0) ans += mod_par;
  }
  cout << ans << '\n';
  for (ll i = 1;i <= m;++i) {
    ans -= i*(i+1)/2;
    while (ans <= 0) ans += mod_par;
  }
  cout << ans << '\n';
  for (ll i = n;i >= 0;--i) {
    if (i >= k) ans -= m*(m-1)/2;
    while (ans <= 0) ans += mod_par;
  }
  cout << ans << '\n';
}