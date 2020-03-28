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

int main() {
  ll K, N;
  cin >> K >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  std::sort(A.begin(), A.end());
  vector<ll> B(N);
  rep(i, N-1) {
    B[i] = A[i+1] - A[i];
  }
  B[N-1] = K - A[N-1] + A[0];
  std::sort(B.begin(), B.end());
  cout << K - B[N-1] << '\n';
}
