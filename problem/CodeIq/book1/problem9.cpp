#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int boy = 20;
  int girl = 10;

  ++boy;
  ++girl;
  vector<vector<int>> dp(girl, vector<int>(boy, 0));
  dp[0][0] =1;
  for (auto i = 0;i < girl;++i) {
    for (auto j = 0;j < boy;++j) {
      if ((i!=j)&&(boy-j!=girl-i)) {
        if (j>0) dp[i][j] += dp[i][j-1];
        if (i>0) dp[i][j] += dp[i-1][j];
      }
    }
  }
  cout << dp[girl-2][boy-1] + dp[girl-1][boy-2] << '\n';
}
