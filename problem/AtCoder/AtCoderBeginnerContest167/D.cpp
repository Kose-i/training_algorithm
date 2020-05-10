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

  ll N;
  ull K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll roop_cnt {};
  ll roop_start_cnt {};
  ll roop_start_pos {};
  int now_pos {};
  vector<int> B(N, -1);
  rep(i, N) {
    if (B[now_pos] != -1) {
      roop_start_cnt = B[now_pos];
      roop_cnt = i - B[now_pos];
      roop_start_pos = now_pos;
      break;
    }
    B[now_pos] = i;
    now_pos = A[now_pos]-1;
  }
//  rep(i, N) {
//    cout << B[i] << ' ';
//  }
//  cout << '\n';
//  cout << roop_start_cnt << ' ' << roop_cnt << ' ' << roop_start_pos+1 << '\n';
//  return 0;
  if (K > roop_start_cnt) {
    ll tmp_K = K - roop_start_cnt;
    tmp_K %= roop_cnt;
    ll answer {roop_start_pos};
    rep(i, tmp_K) {
      answer = A[answer]-1;
    }
    cout << answer +1 << '\n';
  } else {
    ll answer {};
    rep(i, K) {
      answer = A[answer]-1;
    }
    cout << answer+1 << '\n';
  }
}
