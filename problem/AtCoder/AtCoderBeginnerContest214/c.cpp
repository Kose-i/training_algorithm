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

  int n;
  cin >> n;
  vector<ll> s(n);
  vector<ll> t(n);
  rep(i, n) cin >> s[i];
  rep(i, n) cin >> t[i];

  map<int, ll> mp;
  rep(i, n) {
    mp[i] = t[i];
  }
  rep(i, n) {
    if (mp[i] + s[i] < mp[(i + 1) % n]) {
      for (auto idx = i;;++idx) {
        idx %= n;
        if (mp[idx] + s[idx] < mp[(idx+1)%n]) {
          mp[(idx+1)%n] = mp[idx] + s[idx];
        } else {
          break;
        }
      }
    }
  }
  rep(i, n) {
    cout << mp[i] << '\n';
  }
}
