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

struct Pos{
  int x, y;
};

std::string diff(const Pos& now, const Pos& next) {
  std::string ans {};
  for (int tmp = now.x; tmp < next.x;++tmp) {
    ans += 'R';
  }
  for (int tmp = now.x; next.x < tmp;--tmp) {
    ans += 'L';
  }
  for (int tmp = now.y; tmp < next.y;++tmp) {
    ans += 'D';
  }
  for (int tmp = now.y; next.y < tmp;--tmp) {
    ans += 'U';
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<Pos> p(100);
  rep(i, 100) {
    cin >> p[i].y >> p[i].x;
  }

  Pos now_pos; now_pos.x = 0; now_pos.y = 0;
  rep(i, 100) {
    std::cout << diff(now_pos, p[i]) << 'I';
    now_pos = p[i];
  }
  cout << '\n';
}
