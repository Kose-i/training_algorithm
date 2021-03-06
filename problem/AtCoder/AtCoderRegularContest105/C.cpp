#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <numeric>

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

struct Bridge_type {
  int l, v;
};
bool operator<(Bridge_type& left, Bridge_type& right) {
  return left.l < right.l;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> w(n);
  rep(i, n) cin >> w[i];
  std::sort(w.rbegin(), w.rend());

  vector<Bridge_type> bridge(m);
  rep(i, m) cin >> bridge[i].l >> bridge[i].v;
  std::sort(bridge.begin(), bridge.end());

  //std::vector<int> v(n-1, 0);
  //std::iota(v.begin(), v.end(), 1);

  //do {
  //  std::vector<int> number(n);
  //  number[0] = 0;
  //  for (auto i = 0;i < n-1;++i) {
  //    number[i+1] = v[i];
  //  }
  //  vector<int> length(n);
  //} while (std::next_permutation(v.begin(), v.end()));
}
