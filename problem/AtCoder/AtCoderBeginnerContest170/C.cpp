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

  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  std::sort(p.begin(), p.end());

  int min_value{x-0};
  int ans {0};
  int index = 0;
  for (auto i = 0;i <= 101;++i) {
    if (index < n && i == p[index]) {
      ++index;
    } else {
      if (min_value > std::abs(i-x)) {
        min_value = std::abs(i-x);
        ans = i;
      }
    }
  }
  cout << ans << '\n';
}
