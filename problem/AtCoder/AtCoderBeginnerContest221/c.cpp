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
ll make_ll(std::vector<ll>& perm, int left, int right) {
  ll tmp {};
  for (int i=left;i<right;++i) {
    tmp *= 10;
    tmp += perm[i];
  }
  return tmp;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  cin >> s;
  vector<ll> perm(s.size());
  for (int i=0;i<s.size();++i) perm[i] = s[i] - '0';
  std::sort(perm.begin(), perm.end());
  ll ans {};
  do {
    for (int i=0;i<perm.size();++i) {
      ll val1 = make_ll(perm, 0, i);
      ll val2 = make_ll(perm, i, perm.size());
      if (val1 * val2 > ans) ans = val1 * val2;
    }
  } while (std::next_permutation(perm.begin(), perm.end()));
  cout << ans << '\n';
}
