#include <iostream>
#include <vector>

#define rep(i, N) for(int i = 0;i < (N);++i)
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
using ll = long long;
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
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<char>> map(H, std::vector<char>(W));
  rep(i, H) rep(j, W) std::cin >> map[i][j];
  std::vector<std::vector<mint>> dp(H, std::vector<mint>(W, 0));
  rep(i, W) {
    if (map[0][i]=='#') {
      break;
    }
    mint tmp {1};
    dp[0][i] = tmp;
  }
  rep(i, H) {
    if (i == 0) continue;
    rep(j, W) {
      if (map[i][j] == '#') continue;
      else if (j == 0) {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }
  std::cout << dp[H-1][W-1].x << '\n';
}
