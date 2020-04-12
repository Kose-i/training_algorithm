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
  string S;
  cin >> S;
  ll tmp_on{}, tmp_off {};
  int N = S.size();
  {
    rep(i, N) {
      if (i % 2 == 0) {
        if (S[i] == '0') ++tmp_on;
      } else {
        if (S[i] == '1') ++tmp_on;
      }
    }
    rep(i, N) {
      if (i % 2 == 1) {
        if (S[i] == '0') ++tmp_off;
      } else {
        if (S[i] == '1') ++tmp_off;
      }
    }
  }
  cout << min(tmp_on, tmp_off) << '\n';
}