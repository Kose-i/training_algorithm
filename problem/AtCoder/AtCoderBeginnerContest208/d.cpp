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

  int n, m;
  cin >> n >> m;
  vector<vector<ll>> path(n, vector<ll>(n, LLINF));
  rep(i, n) path[i][i] = 0;

  rep(i, m) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    path[a-1][b-1] = c;
  }

  ull ans {};
  rep(k, n) {
    rep(i, k) { //path[k][__] = ?
      rep(j, k) {
        path[k][i] = min(path[k][i], path[k][j]+path[j][i]);
      }
    }
    rep(i, n) {
      rep(j, n) {
        path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
      }
    }
    rep(i, n) {
      rep(j, n) {
        if (path[i][j] < LLINF) ans += path[i][j];
      }
    }
  }
  cout << ans << '\n';
}
