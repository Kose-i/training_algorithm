#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = std::pair<ll, ll>;

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
bool is_rectangle(vector<Pair>& p) {
  ll dx1 = (p[0].first - p[1].first);
  ll dx2 = (p[1].first - p[2].first);
  ll dx3 = (p[2].first - p[0].first);
  ll dy1 = (p[0].second - p[1].second);
  ll dy2 = (p[1].second - p[2].second);
  ll dy3 = (p[2].second - p[0].second);
  if (dx2 * dy1 == dx1 * dy2) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Pair> a(n);
  for (int i=0;i<n;++i) cin >> a[i].first >> a[i].second;
  ll ans {};
  vector<Pair> tmp(3);
  for (int i=0;i<n;++i) {
    tmp[0] = a[i];
    for (int j=i+1;j<n;++j) {
      tmp[1] = a[j];
      for (int k=j+1;k<n;++k) {
        tmp[2] = a[k];
        if (is_rectangle(tmp)) {
          ++ans;
          //cout << i << '-' << j << '-' << k << '\n';
        }
      }
    }
  }
  cout << ans << '\n';
}
