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

  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i=0;i<h;++i) for (int j=0;j<w;++j) cin >> a[i][j];
  bool is_find {false};
  for (int i1=0;i1<h;++i1) {
    for (int i2=i1+1;i2<h;++i2) {
      for (int j1 =0;j1<w;++j1) {
        for (int j2=j1+1;j2<w;++j2) {
          if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]) is_find = true;
        }
      }
    }
  }
  if (is_find) cout << "No\n";
  else cout << "Yes\n";
}
