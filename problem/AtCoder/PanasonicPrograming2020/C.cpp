#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll tmp = c - a - b;
  if (tmp < 0) {
    cout << "No\n";
    return 0;
  } else {
    ull k = ((ull)tmp)*((ull)tmp);
    ull k2 = 4*a*b;
    if (k2 < k) {
      cout << "Yes\n";
      return 0;
    } else {
      cout << "No\n";
      return 0;
    }
  }
}
