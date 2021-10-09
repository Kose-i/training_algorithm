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

ll calc(vector<int>& d)
ll helphelp(ll size, ll tmp, vector<int> d, int& i) {
  --size;
  ++d[i];
  if (size == 0) return calc(d);
  ll ans {};
  for (int num = i;num < 10;++num) {
    ans += helphelp(size, tmp, d, num);
  }
  return ans;
}
ll search_helper(ll prev_multiple, int ketasuu, ll k) {
  ll tmp = k / prev_multiple;
  /*
  tmp を超えないように各桁の数を設定
  ただし桁数ketasuu
  */
  vector<int> d(10, 0);
  ll ans {};
  for (int i = 0;i < 10;++i) {}
    ans += helphelp(ketasuu, tmp, d, i);
  }
  return ans;
}

ll search(ll n, ll k, ll nokori, ll prev_multiple, int ketasuu) {
  if (nokori > max_ketasuu) {
    return search_helper(prev_multiple, ketasuu, k);
  } else {
    return search(n, k, )
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  int ketasuu {};
  for (ll tmp = n;tmp != 0; tmp /= 10) ++ketasuu;
  cout << search(n, ketasuu, ) << '\n';
}
