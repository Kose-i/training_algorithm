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

int get_S(const string& S, int idx) {
  int c = S[idx] - '0';
  c*=10;
  c += S[idx+1] - '0';
  c*=10;
  c += S[idx+2] - '0';
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string S;
  cin >> S;
  int S_size = S.size();
  int mins_target {10000};
  rep (i, S_size-2) {
    mins(mins_target, std::abs(753-get_S(S, i)));
  }
  cout << mins_target << '\n';
}
