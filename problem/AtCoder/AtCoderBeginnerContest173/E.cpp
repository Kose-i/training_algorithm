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

ll mod_target {1000000007};

bool is_hu(const vector<ll>& A, const int& N, const int& K) {
  if (A[N-K] > 0) return false;
  int sei_cnt {};
  int hu_cnt {};
  rep(i, N) {
    if (A[i] < 0) ++hu_cnt;
    else if (A[i] > 0) ++sei_cnt;
  }
  int t = K - sei_cnt;
  if (t <= 0) return false;
  if (t > 0 && hu_cnt >= t && t % 2 == 0) return false;
  int tmp = K - (hu_cnt/2)*2;
  if (K%2 <= sei_cnt && tmp <= sei_cnt) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  std::sort(A.begin(), A.end());

  vector<int> max_index(K);
  rep(i, K) {
    max_index[i] = N - K + i;
  }

  if (is_hu(A, N, K)) {
    vector<ll> B(N);
    rep(i, N) {
      if (A[i] <= 0) B[i] = mod_target+A[i];
      else B[i] = A[i];
    }
    ll answer {1};
    std::sort(B.begin(), B.end());
    rep(i, K) {
      answer *= B[N-i-1];
      answer %= mod_target;
    }
    cout << answer << '\n';
    return 0;
  }

  if (A[0] < 0) {
    for (auto i = 0;i < K/2;i+=2) {
      //cout << A[N-K+i]*A[N-K+i+1] << ' ' <<  A[i]*A[i+1] << '\n';
      if (A[N-K+i]*A[N-K+i+1] < A[i]*A[i+1]) {
        max_index[i] = i;
        max_index[i+1] = i+1;
      } else {
        break;
      }
    }
  }

  ll answer {1};
  rep(i, K) {
    ll tmp = A[max_index[i]] % mod_target;
    if (A[max_index[i]] < 0) tmp = (-1)*A[max_index[i]];
    answer *= tmp;
    answer %= mod_target;
  }
  cout << answer % mod_target << '\n';

}
