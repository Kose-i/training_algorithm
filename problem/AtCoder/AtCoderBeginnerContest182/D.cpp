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

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> b(n);
  b[0] = a[0];
  srep(i,1,n) b[i] = b[i-1] + a[i];

  vector<ll> c(n+1);
  c[0] = 0;
  srep(i,1,n+1) {
    c[i] = b[i-1] + c[i-1];
  }

  vector<ll> max_c(n, 0);
  ll tmp = 0;
  max_c[0] = max(a[0], tmp);
  srep(i,1,n) {
    max_c[i] = max(max_c[i-1], b[i]);
  }

  ll ans {};
  rep(i,n) {
    //cout << c[i] + max_c[i] << '\n';
    maxs(ans, c[i] + max_c[i]);
  }
  maxs(ans , c[n]);
  cout << ans << '\n';
}
