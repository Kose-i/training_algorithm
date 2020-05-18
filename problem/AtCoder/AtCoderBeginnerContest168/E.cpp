#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
//#include <numeric>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  else if (b==0) return a;
  return b?gcd(b,a%b):a;
}

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
using P = std::pair<ll, ll>;
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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  int zero_cnt {};
  map<P, P> mp;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x==0 && y==0) {
      ++zero_cnt;
      continue;
    }
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    if (y < 0) x = -x, y = -y;
    else if (y==0 && x<0) x = -x, y=-y;
    bool rot90 = (x<=0);
    if (rot90) {
      ll tmp = x;
      x = y; y = -tmp;
    }
    if (rot90) ++mp[{x, y}].first;
    else ++mp[{x,y}].second;
  }

  mint ans = 1;
  for (const auto& p : mp) {
    int s = p.second.first;
    int t = p.second.second;
    mint now = 1;
    now += mint(2).pow(s) - 1;
    now += mint(2).pow(t) - 1;
    ans *= now;
  }
  ans -= 1;

  ans += zero_cnt;
  cout << ans.x << endl;
}
