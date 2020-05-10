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

bool is_ok(const string& S, const string& T) {
  int S_size = S.size();
  if (S_size + 1 != T.size()) return false;
  rep(i, S_size) {
    if (S[i] != T[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string S, T;
  cin >> S >> T;

  if (is_ok(S, T)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
