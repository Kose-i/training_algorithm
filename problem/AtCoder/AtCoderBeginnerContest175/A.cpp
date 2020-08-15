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

  std::string S;
  std::cin >> S;

  int ans {};
  bool first {true};
  if (std::find(S.begin(), S.end(), 'R')==S.end()) {
    ans = 0;
  } else { // ans = 1;
    ans = 1;
    if (S[1] == 'R' && (S[0]=='R'||S[2]=='R')) {
      ans = 2;
      if (S[0] == S[1] && S[1] == S[2] && S[0] == 'R') {
        ans = 3;
      }
    }
  }
  std::cout << ans << '\n';
}
