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

ll func_g1(ll x) {
  std::vector<int> vec;
  while (x != 0) {
    vec.push_back(x%10);
    x/=10;
  }
  ll ans {};
  std::sort(vec.rbegin(), vec.rend());
  for (const auto& e : vec) {
    ans *= 10;
    ans += e;
  }
  return ans;
}

ll func_g2(ll x) {
  std::vector<int> vec;
  while (x != 0) {
    vec.push_back(x%10);
    x/=10;
  }
  ll ans {};
  std::sort(vec.begin(), vec.end());
  for (const auto& e : vec) {
    ans *= 10;
    ans += e;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  ll ans = n;
  rep(i, k) {
    ans = func_g1(ans) - func_g2(ans);
  }
  cout << ans << '\n';
}