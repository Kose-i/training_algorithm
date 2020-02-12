#include <iostream>
#include <vector>

const int mod = 1000000007;
using ll = long long;
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

int main(int argc, char** argv) {
  unsigned x_left, y_left, x_right, y_right;
  std::cin >> x_left >> y_left >> x_right >> y_right;
  --x_left;
  --y_left;

  constexpr int N {200005};
  std::vector<mint> factorial(N+1, 1);
  std::vector<mint> inverse_factorial(N+1, 1);
  for (ll i = 1;i <= N;++i) {
    factorial[i] = factorial[i-1]*i;
  }
  inverse_factorial[N] = factorial[N].inv();
  for (int i = N; i >= 1; --i) inverse_factorial[i-1] = inverse_factorial[i]*i;
  auto g = [=](mint l, mint r) {
    return factorial[l.x+r.x+2]*(inverse_factorial[l.x+1]*inverse_factorial[r.x+1]) - 1;
  };

  mint Ans = g(x_right, y_right);
  Ans -= g(x_right, y_left);
  Ans -= g(y_right, x_left);
  Ans += g(x_left, y_left);
  std::cout << Ans.x << '\n';
}
