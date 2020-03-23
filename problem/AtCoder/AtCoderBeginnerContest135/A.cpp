#include <algorithm>
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

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

int main() {
  int A, B;
  cin >> A >> B;
  if (A > B) {
    int tmp = A;
    A = B;
    B = tmp;
  }
  int K = (B - A)/2 + A;
  if ((B - A) % 2 == 1) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << K << '\n';
  }
}
