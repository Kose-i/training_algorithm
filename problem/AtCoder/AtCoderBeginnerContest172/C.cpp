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

  int n, m;
  ull k;
  cin >> n >> m >> k;

  vector<ull> A(n);
  rep(i, n) cin >> A[i];
  vector<ull> B(m);
  rep(i, m) cin >> B[i];

  vector<ull> A_souwa(n+1);
  A_souwa[0] = 0;
  srep(i, 1, n+1) A_souwa[i] = A_souwa[i-1] + A[i-1];
  vector<ull> B_souwa(m+1);
  B_souwa[0] = 0;
  srep(i, 1, m+1) B_souwa[i] = B_souwa[i-1] + B[i-1];

  int ans {};
  int index_B {m};
  rep (i, n+1) {
    if (A_souwa[i] > k) break;
    while (A_souwa[i] + B_souwa[index_B] > k) {
      --index_B;
    }
    maxs(ans, i+index_B);
  }
  cout << ans << '\n';
}
