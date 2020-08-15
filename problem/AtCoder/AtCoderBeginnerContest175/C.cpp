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

  ll first_pos, K, D;
  cin >> first_pos >> K >> D;
  if (first_pos < 0) first_pos = (-1)*first_pos;
  ll cnt {first_pos/D};
  ll pr_len {first_pos%D};

  ll ans {};
  if (K < cnt) {
    ans = first_pos -K*D;
  } else {
    cnt = K - cnt;
    cnt %= 2;
    if (cnt == 0) {
      ans = pr_len;
    } else if (cnt == 1) {
      ans = D - pr_len;
    }
  }
  cout << ans << '\n';
}
