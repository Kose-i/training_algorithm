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

  int t;
  cin >> t;
  vector<int> n(t);
  vector<vector<int>> a(t);
  vector<vector<int>> b(t);
  for (int i = 0;i<t;++i) {
    cin >> n[i];
    vector<int> tmp(n[i]);
    for (int j = 0;j < n[i];++j) cin >> tmp[j];
    a[i] = tmp;
    for (int j = 0;j < n[i];++j) cin >> tmp[j];
    b[i] = tmp;
  }

  for (int i=0;i<t;++i) {
    int ans {n[i]};
    for (int j=0;j<n[i];++j) {
        int k = 0;
        for (;k<n[i];++k) {
            if (ans < j+k) break;
            if (a[i][j] < b[i][k]) break;
        }
        if (j+k < ans) ans = j+k;
    }
    cout << ans << '\n';
  }
}
