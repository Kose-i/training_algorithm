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

  ll N;
  cin >> N;

  ll tmp {1};
  int bit_cnt {1};
  for (int i = 1; tmp != 0;++i) {
    if ((N&tmp) != 0) bit_cnt = i;
    tmp <<= 1;
  }
  cout << "bit_cnt :" <<  bit_cnt << '\n';

  vector<int> answer(bit_cnt);
  tmp = 1;
  rep(i, bit_cnt) {
    if (tmp&N == 0) answer[i] = 0;
    else answer[i] = 1;
    N = ~N;
    tmp <<= 1;
  }
  drep(i, bit_cnt) {
    cout << answer[i];
  }
  cout << '\n';
}
