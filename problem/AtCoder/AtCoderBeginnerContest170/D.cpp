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

#include <vector>
#include <utility>

using namespace std;
using P = std::pair<int, int>;
using ll = long long;

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

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

bool divisible(const vector<P>& X, const vector<P>& Y) {
  int X_size = X.size();
  int Y_size = Y.size();
  if (X_size > Y_size) return false;
  int index {};
  for (auto i = 0;i < X_size;++i) {
    for (;index < Y_size;++index) {
      if (X[i].first == Y[index].first) {
        break;
      }
    }
    if (index == Y_size) return false;
    if (Y[index].second < X[i].second) return false;
    ++index;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  std::sort(A.begin(), A.end());
  Sieve sieve(100000);
  vector<vector<P>> factor_A(n);
  rep(i, n) {
    factor_A[i] = sieve.factor(A[i]);
  }

  vector<char> is_ok(n, 1);

  int ans {};
  rep(i, n) {
    if (i!=n-1&&A[i]==A[i+1]) {
      is_ok[i] = 0;
      is_ok[i+1] = 0;
    }
    if (is_ok[i]==0) continue;
    srep(j,i+1,n) {
      if (divisible(factor_A[i], factor_A[j])) {
        is_ok[j] = 0;
      }
    }
    ++ans;
  }
  cout << ans << '\n';
}
