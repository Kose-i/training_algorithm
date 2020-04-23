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

struct Pos {
  int x, y;
  ull h;
};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  cin >> N;
  vector<Pos> X(N);
  rep(i, N) cin >> X[i].x >> X[i].y >> X[i].h;
  for (int x_left=0, x_right=100;x_right-x_left<=1;) {
    int x_mid = (x_right + x_left)/2;
    for (int y_left=0,y_right=100;y_right-y_left<=1;) {
      int y_mid = (y_right+y_left)/2;
    }
  }
}
