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

bool check(const std::string& s, const std::string& check_s) {
  for (int i = 0;i < 10;++i) {
    if (s[i] == 'o') {
      if (std::find(check_s.begin(), check_s.end(), '0'+i) == check_s.end()) return false;
    } else if (s[i] == 'x') {
      if (std::find(check_s.begin(), check_s.end(), '0'+i) != check_s.end()) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n {10};
  std::string s;
  cin >> s;

  ll ans {};

  for (int i = 0;i < 10000;++i) {
    std::string check_s;
    check_s += '0' + (i/1000);
    check_s += '0' + ((i/100)%10);
    check_s += '0' + ((i/10)%10);
    check_s += '0' + (i%10);
    if (check(s, check_s)) ++ans;
  }
  cout << ans << '\n';
}
