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

  ll n; cin >> n;
  const std::string S {"110"};
  std::string T; cin >> T;
  constexpr ll const_n {30000000000};
  //constexpr ll const_n {3};

  ll ans {};

  rep(i, 3) {
    bool is_find {true};
    rep(j, n) {
      if (T[j] != S[(i+j)%3]) {
        is_find = false;
        break;
      }
    }
    if (is_find == true) {
      ans += (const_n - n- i) / S.size() + 1;
    }
  }
  cout << ans << '\n';
}
