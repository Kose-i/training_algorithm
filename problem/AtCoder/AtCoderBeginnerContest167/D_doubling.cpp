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
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
    --A[i];
  }

  vector<vector<int>> Table;
  for (ull i = 0, k = 1;k <= K;++i, k<<=1) {
    vector<int> B(N);
    if (i==0) B = A;
    else {
      rep(j, N) {
        B[j] = Table[i-1][Table[i-1][j]];
      }
    }
    Table.push_back(B);
  }
  ll K_tmp = K;
  int answer {};
  for (ll i = 0;K_tmp!=0;++i, K_tmp>>=1) {
    if (K_tmp&1) {
      answer = Table[i][answer];
    }
  }
  cout << answer + 1 << '\n';
}
