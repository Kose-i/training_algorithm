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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  vector<ll> B(N, 0);
  ll tmp_x {};
  rep(i, N) {
    if (i % 2 == 0) {
      tmp_x += A[i];
    } else {
      tmp_x -= A[i];
    }
  }
  B[0] = tmp_x/2;
  srep(i, 1, N) {
    B[i] = A[i-1] - B[i-1];
  }

  bool is_first {true};
  rep(i, N) {
    if (is_first == true) {
      is_first = false;
    } else {
      cout << ' ';
    }
    cout << B[i]*2;
  }
  cout << '\n';
}
