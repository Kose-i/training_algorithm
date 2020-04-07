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


#include <utility>

using P = std::pair<int , int>;
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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ull> A(N);
  rep(i, N) cin >> A[i];
  Sieve tmp(1000000000);
  vector<vector<P>> Factor_list(N);
  rep(i, N) {
    Factor_list[i] = tmp.factor(A[i]);
  }
  sort(Factor_list.begin(), Factor_list.end(), [](auto& l, auto& r){return l.size()<r.size();});
  vector<int> factor_prime_element;//[0], [1] factor
  for (int i = 0;i <= 1;++i) {
    for (const auto& e : Factor_list[i]) {
      if (find(factor_prime_element.begin(), factor_prime_element.end(), e.first) == factor_prime_element.end()) {
        factor_prime_element.push_back(e.first);
      }
    }
  }
  std::sort(factor_prime_element.begin(), factor_prime_element.end());
  for (const auto& e : factor_prime_element) {
    cout << e << ' ';
  }
  cout << '\n';
}
