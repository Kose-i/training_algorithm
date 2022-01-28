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

  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i=0;i<n;++i) cin >> a[i];
  std::sort(a.begin(), a.end());
  
  ll sum {};
  int diff = n - k;
  if (diff == 0) {
    cout << a[0] << '\n';
    return 0;
  }

  for (int i=0;i<diff;++i) {
    sum += a[i];
  }

  ll ans {};

  for (int i=diff;i<n;++i) {
    if (a[i] < (sum + a[i]) / (i - diff + 1)) {
      sum += a[i];
      ans = sum / (i-diff + 1);
    } else {
      ans = min(ans, a[i]);
      break;
    }
  }

  cout << ans << '\n';
}
