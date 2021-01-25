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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> table(n, vector<int>(n, INTINF));
  //table[l][r]
  rep(i, n) table[i][i] = a[i];

  rep(i, n-1) {
    rep(j, n-i-1) {
      table[j][i+j+1] = min(table[j][i+j], table[j+1][i+j+1]);
    }
  }

  int ans {};
  rep(l, n) {
    srep(r, l, n) {
      int tmp = table[l][r] * (r - l + 1);
      maxs(ans, tmp);
    }
  }
  cout << ans << '\n';
}
