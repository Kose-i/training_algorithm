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

  int h, w;
  cin >> h >> w;
  vector<vector<int>> board(h, vector<int>(w));
  rep(i, h) rep(j, w) {
    int c; cin >> c;
    if (c == '+') board[i][j] = 1;
    else board[i][j] = -1;
  }

  vector<vector<int>> dp(h, vector<int>(w));

  int digit_i {-1};
  drep(i, h) {
    int digit_j {digit_i};
    drep(j, w) {
      if (i==h-1 &&j==w-1) dp[i][j] = 0;
      else if (i == h-1) dp[i][j] = dp[i][j+1] + board[i][j+1]*digit_j;
      else if (j == w-1) dp[i][j] = dp[i+1][j] + board[i+1][j]*digit_j;
      else if (digit_i*digit_j < 0) dp[i][j] = std::max(dp[i+1][j] +board[i+1][j], dp[i][j+1] + board[i][j+1]);
      else if (digit_i*digit_j > 0) dp[i][j] = std::min(dp[i+1][j] +board[i+1][j], dp[i][j+1] + board[i][j+1]);

      digit_j *= (-1);
    }
    digit_i *= (-1);
  }

  //rep(i, h) {
  //  rep(j, w) {
  //    cout << dp[i][j] << ' ';
  //  }
  //  cout << '\n';
  //}

  if ((h == w && h == 1) || dp[0][0] == 0) cout << "Draw\n";
  else if ((h+w)%2 == 0 && dp[0][0] > 0) cout << "Aoki\n";
  else if ((h+w)%2 == 0 && dp[0][0] < 0) cout << "Takahashi\n";
  else if ((h+w)%2 == 1 && dp[0][0] > 0) cout << "Takahashi\n";
  else cout << "Aoki\n";
}