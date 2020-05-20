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

using P = std::pair<int, int>;
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<P> X(n);
  rep(i, n) cin >> X[i].first >> X[i].second;
  constexpr int N {2000000+1};
  vector<int> number(N, 1);
  number[0] = number[1] = 0;
  rep(i, N) {
    if (number[i] == 1) {
      number[i] = i;
      for (auto j = i+i;j <= N;j+=i) {
        if (number[j] == 1) number[j] = i;
      }
    }
  }
  rep(i, n) {
    int ans {X[i].first};
    ans += number[ans];
    ans += 2*(X[i].second-1);
    cout << ans << '\n';
  }
}
