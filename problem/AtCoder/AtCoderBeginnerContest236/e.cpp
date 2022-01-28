

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
  rep(i, n) cin >> a[i];

  ll l, r;

  for (l=0, r=10010010010000;r - l > 1;) {
    ll mid = (l+r)/2;
    vector<vector<ll>> dp_mean(n, vector<ll>(2, 0));
    dp_mean[0][0] = (a[0]*10000 - mid);
    dp_mean[0][1] = 0;
    for (int i=1;i<n;++i) {
      dp_mean[i][0] = max(dp_mean[i-1][0]+a[i]*10000-mid, dp_mean[i-1][1]+a[i]*10000-mid);
      dp_mean[i][1] = dp_mean[i-1][0];
    }
    if (dp_mean[n-1][0]>=0||dp_mean[n-1][1] >=0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << std::fixed << l/static_cast<double>(10000) <<  '\n';

  for (l=0, r=1001001001;r - l > 1;) {
    ll mid = (l+r)/2;
    vector<vector<ll>> dp_mean(n, vector<ll>(2, 0));
    dp_mean[0][0] = ((a[0]<mid)?-1:1);
    dp_mean[0][1] = 0;
    for (int i=1;i<n;++i) {
      dp_mean[i][0] = max(dp_mean[i-1][0]+((a[i]<mid)?-1:1), dp_mean[i-1][1]+((a[i]<mid)?-1:1));
      dp_mean[i][1] = dp_mean[i-1][0];
    }
    if (dp_mean[n-1][0]>0|| dp_mean[n-1][1]>0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l <<  '\n';
}