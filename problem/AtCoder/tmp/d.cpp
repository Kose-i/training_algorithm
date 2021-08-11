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

  int n, q_cnt;
  cin >> n >> q_cnt;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ull> query(q_cnt);
  rep(i, q_cnt) cin >> query[i];

  std::sort(a.begin(), a.end());
  rep(i, q_cnt) {
    ull ans = query[i];
    for (;;) {
      auto it = std::upper_bound(a.begin(), a.end(), ans);
      ull tmp = query[i] + std::distance(a.begin(), it);
      if (tmp != ans) ans = tmp;
      else break;
    }
    cout << ans << '\n';
  }
}
