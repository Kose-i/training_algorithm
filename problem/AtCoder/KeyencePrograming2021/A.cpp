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

  int n;cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }

  vector<ll> c(n, 0);
  c[0] = a[0] * b[0];

  vector<ll> a_now_max(n);
  a_now_max[0] = a[0];
  srep(i, 1, n) {
    if (a_now_max[i-1] < a[i]) {
      a_now_max[i] = a[i];
    } else {
      a_now_max[i] = a_now_max[i-1];
    }
  }

  ll a_now_max_val = a_now_max[0];
  ll b_now_max_val = b[0];
  rep(i, n) {
    c[i] = a_now_max_val * b_now_max_val;
    if (c[i] < a_now_max_val * b[i]) {
      b_now_max_val = b[i];
    }
    if (c[i] < a_now_max[i] * b[i]) {
      a_now_max_val = a_now_max[i];
      b_now_max_val = b[i];
    }
    c[i] = a_now_max_val * b_now_max_val;
  }

  rep(i, n) cout << c[i] << '\n';
}
