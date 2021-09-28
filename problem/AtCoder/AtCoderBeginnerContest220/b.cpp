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
ll make_bit(ll a, int c) {
    ll ans {};
    ll tmp {1};
    while (a != 0) {
        ans += (a%10)*tmp;
        a/=10;
        tmp *= c;
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int k;
  ll a, b;
  cin >> k >> a >> b;
  ll c, d;
  c = make_bit(a, k);
  d = make_bit(b, k);
  cout << c * d << '\n';
}
