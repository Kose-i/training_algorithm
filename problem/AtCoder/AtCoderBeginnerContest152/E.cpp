#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <numeric>

/*snuke*/

#define rep(i,n) for (int i = 0; i < (n); ++i)

using ll = long long;
using P = std::pair<int,int>;
 
constexpr int mod {1000000007};
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
 
 
struct Sieve {
  int n;
  std::vector<int> f, primes;
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
  std::vector<int> factorList(int x) {
    std::vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  std::vector<P> factor(int x) {
    std::vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    std::vector<P> res(1, P(fl[0], 0));
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
 
int main(int argc, char** argv) {
  Sieve sieve(1000000);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i,n) std::cin >> a[i];
 
  std::map<int,int> mp;
  rep(i,n) {
    auto f = sieve.factor(a[i]);
    for (auto p : f) {
      mp[p.first] = std::max(mp[p.first], p.second);
    }
  }
 
  mint lcm = 1;
  for (auto p : mp) {
    rep(i,p.second) {
      lcm *= p.first;
    }
  }
 
  mint ans;
  rep(i,n) {
    mint b = lcm/a[i];
    ans += b;
  }
  std::cout << ans.x << '\n';
  return 0;
}
