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
constexpr int INTINF {100000000};

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
  int N, X, Y;
  cin >> N >> X >> Y;
  --X; --Y;
  vector<vector<int>> dp(N, vector<int>(N, INTINF));
  rep(i, N) {
    srep(j, i+1,N)
    dp[i][j] = std::min(j-i, std::abs(Y-j)+std::abs(X-i)+1);
  }
  vector<int> answer(N+1);
  rep(i, N) {
    srep(j, i+1, N) {
      ++answer[dp[i][j]];
    }
  }
  srep(i, 1, N) {
    cout << answer[i] << '\n';
  }
}
