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

  int n;
  cin >> n;
  vector<int> query(n);
  for (int i=0;i<n;++i) cin >> query[i];

  vector<int> s(1000+1, 0);
  for (int a=1;a<=1000;++a) {
    for (int b=1;b<=1000;++b) {
      if (4*a*b+3*a+3*b <= 1000) {
        s[4*a*b + 3*a+3*b] = 1;
      }
    }
  }

  int ans {};
  for (int i=0;i<n;++i) {
    if (s[query[i]] == 0) ++ans;
  }
  cout << ans << '\n';
}