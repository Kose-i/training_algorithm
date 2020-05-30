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
  ++n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  vector<ull> B(n);
  B[n-1] = A[n-1];
  drep(i,n-1) {
    B[i] = B[i+1] + A[i];
  }

  vector<ull> D(n, 0);
  ull c {1};
  int index {-1};
  rep(i,n) {
    D[i] = c;
    if (B[i] <= D[i]) {
      index = i;
      break;
    }
    if (c < A[i]) {
      index = -1;
      break;
    }
    c -= A[i];
    c <<= 1;
  }
//  rep(i, n) {
//    cout << B[i] << ' ' << D[i] << '\n';
//  }

  if (index == -1) {
    cout << "-1\n";
    return 0;
  }

  ull ans {0};
  rep(i, index) {
    ans += D[i];
//    cout << ans << '\n';
  }
  ans += min(B[index], D[index]);
  srep(i, index+1, n) {
    ans += B[i];
//    cout << ans << '\n';
  }

  cout << ans << '\n';
}
