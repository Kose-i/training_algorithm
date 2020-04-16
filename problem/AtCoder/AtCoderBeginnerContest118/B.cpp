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
  int N, M;
  cin >> N >> M;
  vector<int> K(N);
  vector<vector<int>> A(N);
  rep(i, N) {
    cin >> K[i];
    vector<int> A_tmp(K[i]);
    rep(j, K[i]) {
      cin >> A_tmp[j];
    }
    A[i] = A_tmp;
  }

  vector<vector<char>> C(N, vector<char>(M, 0));
  rep(i, N) {
    rep(j, K[i]) {
      C[i][A[i][j]-1] = 1;
    }
  }

  int answer {};
  rep(i, M) {
    char sum {};
    rep(j, N) {
      sum += C[j][i];
    }
    if (sum == N) ++answer;
  }
  cout << answer << '\n';
}
