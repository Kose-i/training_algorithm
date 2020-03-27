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

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

ull gcd(const ull& a, const ull& b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ull A, B, C, D;
  cin >> A >> B >> C >> D;

  ull N = B - A + 1;
  ull a = (B/C) - ((A-1)/C);
  ull b = (B/D) - ((A-1)/D);

  ull CD_prime = C*D/gcd(C, D);

  ull ab = (B/CD_prime) - ((A-1)/CD_prime);

  cout << (N+ab-a-b) << '\n';
}
