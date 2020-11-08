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
  
  std::string s;
  cin >> s;

  std::vector<int> pub(3, 0);
  for (const auto& e : s) {
    ++pub[(e - '0') % 3];
  }

  int ans {9};
  for (int i = 0;i < 3;++i) {
    if (pub[1] < i) break;
    for (int j = 0;j < 3;++j) {
      if (pub[2] < j) break;
      if (((pub[1]-i) + 2*(pub[2]-j)) %3 == 0) {
        ans = min(ans, i+j);
      }
    }
  }

  if (ans > 6 || ans == s.size()) {
    ans = -1;
  }
  cout << ans << '\n';
}
