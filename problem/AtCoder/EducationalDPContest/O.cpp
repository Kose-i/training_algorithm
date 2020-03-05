#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
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
  int N;
  std::cin >> N;
  std::vector<std::vector<char>> a(N, std::vector<char>(N));
  rep(i, N) rep(j, N) std::cin >> a[i][j];

  int n = 1<<N;
  std::vector<mint> dp(n, 0);
  dp[0] = 1;

  std::vector<int> bc(n, 0);
  rep(i,n) {
    bc[i] = bc[i/2] + (i%2);
  }

  rep(i, n-1) {
    int s = bc[i];
    rep(j,n) {
      if ()
    }
  }
  std::cout << dp[n-1] << '\n';
}
