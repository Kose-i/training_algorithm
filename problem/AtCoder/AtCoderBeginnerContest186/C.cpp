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

bool is_eight_not_seven(const int& t) {
  int c = t;
  while (c != 0) {
    if (c % 8 == 7) return false;
    c /= 8;
  }
  return true;
}
bool is_ten_not_seven(const int& t) {
  int c = t;
  while (c != 0) {
    if (c % 10 == 7) return false;
    c /= 10;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  int ans {};
  srep(i, 1, n+1) {
    if (is_eight_not_seven(i) && is_ten_not_seven(i)) {
      ++ans;
    }
  }
  cout << ans << '\n';
}
