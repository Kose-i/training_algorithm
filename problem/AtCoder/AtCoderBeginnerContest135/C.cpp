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
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  rep(i, N+1) cin >> A[i];
  vector<ll> B(N);
  rep(i, N) cin >> B[i];

  ll answer {};
  ll primary = A[N];
  drep(i, N) {
    if (B[i] > primary) {
      answer += primary;
      ll atack = B[i] - primary;
      if (atack < A[i]) {
        primary = A[i] - atack;
        answer += atack;
      } else { // atack >= A[i]
        primary = 0;
        answer += A[i];
      }
    } else {
      answer += B[i];
      primary = A[i];
    }
  }
  cout << answer << '\n';
}
