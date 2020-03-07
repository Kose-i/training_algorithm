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
  double A, B;
  cin >> A >> B;
  constexpr double a_partial = 0.08;
  constexpr double b_partial = 0.10;

  bool is_minus = false;

  int left = 0;
  for (;left < 100000;++left) {
    double c = floor(left*a_partial);
    double d = floor(left*b_partial);
    if (c > A || d > B) {
      is_minus = true;
      break;
    } else if (c == A && d == B) {
      break;
    }

  }

  if (is_minus == true) {
    cout << "-1\n";
  } else {
    cout << left << '\n';
  }
}
