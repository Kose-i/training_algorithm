#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

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

  ull n;
  cin >> n;

  std::string stone;
  std::cin >> stone;

  std::queue<int> w_pos;
  std::queue<int> r_pos;

  rep(i, n) {
    if (stone[i] == 'W') w_pos.push(i);
  }
  drep(i, n) {
    if (stone[i] == 'R') r_pos.push(i);
  }

  ull ans {};
  for (;w_pos.size() != 0 && r_pos.size() != 0;++ans) {
    int w_p = w_pos.front(); w_pos.pop();
    int r_p = r_pos.front(); r_pos.pop();
    if (w_p > r_p) break;
  }
  cout << ans << '\n';
}
