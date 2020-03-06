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

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

int main() {
  int N;
  cin >> N;
  vector<ull> value(N);
  rep(i,N) cin >> value[i];
  vector<vector<double>> dp(N, vector<double>(N, 0));
  rep(i,N) dp[i][i] = value[i];
  drep(l,N) srep(r, l, N) {
    if (l == r) dp[l][r] = value[l];
    else {
      srep(k,l,r) {
        dp[l][r] = std::max(dp[l][r], (dp[l][k]+dp[k+1][r])/2.0);
      }
    }
  }
  std::cout << dp[0][N-1] << '\n';
}
