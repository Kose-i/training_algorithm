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

ull conv(int n, int N) {
  //a + b == n
  // 1 <= a <= N
  // 1 <= b <= N
  if (n <= N) return n-2+1;// (n-2)+1 C 1

  int new_n {n - 2};
  int t {N-1 - new_n};
  // 0<= a <= N-1
  // 0<= b <= N-1
  return (N-1)*2 - new_n +1;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  if (k < 0) k = -k;

  ull ans {};
  //ans = conv(4, 2);
  for (auto A = k + 2;A <= 2*n; ++A) {
    int B = A - k;
    ans += conv(A, n)*conv(B, n);
    //cout << "A:" << A << " B:" << B << "\n";
    //cout << ans << '\n';
  }
  cout << ans << '\n';
}
