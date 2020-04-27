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

using P = std::pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<P> X(4);
  rep(i, 2) cin >> X[i].first >> X[i].second;

  int dx = X[1].first  - X[0].first;
  int dy = X[1].second - X[0].second;

  X[2].first  = X[1].first  - dy;
  X[2].second = X[1].second + dx;
  X[3].first  = X[2].first  - dx; 
  X[3].second = X[2].second - dy;

  cout << X[2].first << ' ' << X[2].second << ' ';
  cout << X[3].first << ' ' << X[3].second << '\n';
}
