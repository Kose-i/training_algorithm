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

ull conv(const int& x, const int& y, const int& z) {
  if (x==y&&y==z) return 1;
  else if (x==y||y==z) return 3;
  else return 6;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ull> pattern(n+1, 0);
  for (int x = 1;x < n;++x) {
    int tmp1 = x*x;
    if (tmp1 > n) break;
    for (int y = x;y < n;++y) {
      int tmp2 = tmp1 + x*y + y*y;
      if (tmp2 > n) break;
      for (int z = y;z < n;++z) {
        int tmp3 = tmp2 + z*z + y*z + z*x;
        if (tmp3 > n) break;
        pattern[tmp3] += conv(x,y,z);
      }
    }
  }
  rep(i, n) {
    cout << pattern[i+1] << '\n';
  }
}
