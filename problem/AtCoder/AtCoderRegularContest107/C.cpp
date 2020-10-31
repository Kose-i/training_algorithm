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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
//const int mod = 1000000007;
const int mod = 998244353;
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
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n) {
    rep(j, n) cin >> a[i][j];
  }

  vector<int> move_rows;

  rep(i, n) {
    int min_v = a[i][0];
    rep(j, n) {
      mins(min_v, a[i][j]);
    }
    rep(j, n) {
      if (a[i][j]+min_v > k && std::find(move_rows.begin(), move_rows.end(), j) != move_rows.end()) {
        move_rows.push_back(j);
      }
    }
  }
  int not_move_rows = move_rows.size();

  vector<int> move_cols;
  rep(i, n) {
    int min_v = a[0][i];
    rep(j, n) {
      mins(min_v, a[j][i]);
    }
    rep(j, n) {
      if (a[j][i]+min_v > k && std::find(move_cols.begin(), move_cols.end(), j) != move_cols.end()) {
        move_cols.push_back(j);
      }
    }
  }
  int not_move_cols = move_cols.size();
  
  //cout << not_move_rows << ' ' <<  not_move_cols<<'\n';
  mint ans {1};
  srep(i,1, n - not_move_rows+1) {
    ans *= mint{i};
  }
  srep(i, 1,n - not_move_cols+1) {
    ans *= mint{i};
  }
  cout << ans << '\n';
}
