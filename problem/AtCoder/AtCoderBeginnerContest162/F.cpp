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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  if (N%2==0) {
    ll answer_even {};
    ll answer_odd {};
    rep(i, N) {
      if (i%2==0)answer_even += A[i];
      else answer_odd += A[i];
    }
    ll answer = max(answer_even, answer_odd);
    cout << answer << '\n';
  } else {// N%2==1
    vector<vector<ll>> dp(N, vector<ll>((N/2)+1, -LLINF));
    dp[0][0] = 0;
    dp[0][1] = A[0];
    dp[1][0] = 0;
    dp[1][1] = max(A[1], dp[0][1]);
    srep(i, 2, N) {
      srep(k,i/2-1, N/2+1) {//
        dp[i][k] = max(dp[i-2][k-1] + A[i], dp[i-1][k]);
        if (i > 2) maxs(dp[i][k], dp[i-3][k-1]+A[i]);
      }
    }
    cout << dp[N-1][N/2] << '\n';
  }
}
