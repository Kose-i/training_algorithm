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

  int n; cin >> n;
  std::vector<ll> primes(n+1, 1);
  for (auto i = 2;i <= n;++i) {
    if (primes[i] == 0) continue;
    for (auto j = i+i;j <= n;j += i) {
      primes[j] = 0;
    }
  }

  std::vector<ll> primesf;
  for (auto i = 2;i <= n;++i) {
    if (primes[i] == 1) {
      int tmp = i;
      while (tmp*i <= n) tmp*=i;;
      primesf.push_back(tmp);
    }
  }
  //for (const auto& e : primesf) cout << e << ' ';
  //cout << '\n';

  ll ans {1};
  for (const auto& e : primesf) ans *= e;
  ++ans;
  cout << ans << '\n';
}
