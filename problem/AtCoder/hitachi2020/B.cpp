#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

struct P {
  ll x, y, c;
};

int main() {
  ll A, B, M;
  cin >> A >> B >> M;
  vector<ll> a(A);
  vector<ll> b(B);
  vector<P> d(M);
  rep(i,A) cin >> a[i];
  rep(i,B) cin >> b[i];
  rep(i,M) cin >> d[i].x >> d[i].y >> d[i].c;
  ll minest {a[0]+b[0]};

  rep(i,M) {
    mins(minest, a[d[i].x-1]+b[d[i].y-1]-d[i].c);
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  mins(minest, a[0]+b[0]);
  maxs(minest, 0ll);
  cout << minest << '\n';
}
