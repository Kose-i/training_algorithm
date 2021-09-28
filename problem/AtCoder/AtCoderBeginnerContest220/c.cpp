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

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i=0;i<n;++i) cin >> a[i];
  ll x;
  cin >> x;

  vector<ll> a_wa(n+1, 0);
  for (int i=0;i<n;++i) a_wa[i+1] = a_wa[i] + a[i];

  ll ans {};
  ans += (x / a_wa[n]) * n;
  ll tmp = x % a_wa[n];
  auto it = std::upper_bound(a_wa.begin(), a_wa.end(), tmp);
  ans += (it - a_wa.begin());
  cout << ans << '\n';
}
