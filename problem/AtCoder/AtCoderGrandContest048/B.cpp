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

struct idx_param{
  int idx;
  int value;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<idx_param> data(n);
  rep(i, n) {
    data[i].idx = i;
    data[i].value = a[i] - b[i];
  }
  std::sort(data.begin(), data.end(), [](idx_param& left, idx_param& right){return left.value>right.value;});

  int left_circ {}; // %2==0 => + ,, %2==1 => -

  // data[i] == 0

  ll ans {};
  for (index_equal = 0;index_equal < n;++index_equal) {
    ans += a[data[i].idx];
    left_circ += ((data[i].idx%2 == 0)?1:-1);
    if (data[i].value <= 0) break;
  }
  if (left_circ == 0) {
    for (;index_equal<n;++index_equal) {
      ans += a[data[i].idx];
    }
  } else if (left_circ > 0) {
    int index_right{index_equal+1};
    int index_left {index_equal}
    for (;index_left != 0 || index_right != n-1;) {
      if (left_circ == 0) break;
    }
    for (index_right<n;++index_right) ans += a[data[i].idx];
  } else {//left_circ < 0
    int index_right{index_equal+1};
    int index_left {index_equal}
  }
}
