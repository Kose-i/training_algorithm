#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)
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

int main() {
  ll n, a, b;
  std::cin >> n >> a >> b;
  mint answer(2);
  answer = answer.pow(n);
  //std::cout << answer.x << '\n';
  answer -= 1;
  mint minus(1);
  mint x=1, y=1;
  for (ll i = 0;i < a;++i) {
    x *= n-i;
    y *= i+1;
  }
  answer -= x/y;
  x = 1, y = 1;
  for (ll i = 0;i < b;++i) {
    x *= n-i;
    y *= i+1;
  }
  answer -= x/y;
  std::cout << answer.x << '\n';
}
