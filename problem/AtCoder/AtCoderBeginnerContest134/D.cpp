#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

int main() {
  ll N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<int> b(N+1, 0);
  for (auto i = N;i > 0;--i) {
    int sum_c {};
    for (auto j = i;j < N+1;j+=i) {
      sum_c += b[j];
    }
    if (sum_c % 2 != 0 && a[i-1] == 0) {
      b[i] = 1;
    } else if (sum_c % 2 == 0 && a[i-1] != 0) {
      b[i] = 1;
    }
  }

  int cnt {};
  rep(i, N+1) {
    if (b[i] != 0) ++cnt;
  }
  if (cnt == 0) {
    cout << cnt << '\n';
  } else {
    cout << cnt << '\n';
    rep(i, N+1) {
      if (b[i] != 0) cout << b[i] << '\n';
    }
  }
}
