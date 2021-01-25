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

ll backsearch(const int& idx, const std::vector<std::string>& s, const std::vector<ll>& two_pow) {
  if (idx == -1) return 1;
  if (s[idx] == "AND") {
    return backsearch(idx-1, s, two_pow);
  } else {
    return backsearch(idx-1, s, two_pow) + two_pow[idx+1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  std::vector<std::string> s(n);
  std::vector<ll> two_pow(n+1);
  two_pow[0] = 1;
  srep(i,1, n+1) {
    two_pow[i] = 2 * two_pow[i-1];
  }

  rep(i, n) cin >> s[i];

  cout << backsearch(n-1, s, two_pow) << '\n';
}
