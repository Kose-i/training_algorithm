#include <iostream>
#include <vector>

using namespace std;

int H, W;
constexpr int max(int a, int b) {
  return (a<b)?b:a;
}
constexpr int INF {10000000};

void plot_maze(vector<vector<char>>& maze, vector<vector<int>>& dp) {
  for (auto i = 0;i < H*W;++i) dp[i][i] = 0;
  for (auto i = 0;i < H;++i) {
    for (auto j = 0;j < W;++j) {
      if (i != 0) dp[W*i+j][W*(i-1)+j] = (maze[i-1][j]=='#')?INF:1;
      if (i != H-1) dp[W*i+j][W*(i+1)+j] = (maze[i+1][j]=='#')?INF:1;
      if (j != 0) dp[W*i+j][W*i+(j-1)] = (maze[i][j-1]=='#')?INF:1;
      if (j != W-1) dp[W*i+j][W*i+(j+1)] = (maze[i][j+1]=='#')?INF:1;
    }
  }
}

int main(int argc, char** argv) {
  cin >> H >> W;
  vector<vector<char>> maze(H, vector<char>(W, 0));
  for (auto i = 0;i < H;++i) {
    for (auto j = 0;j < W;++j) {
      cin >> maze[i][j];
    }
  }
  vector<vector<int>> dp(H*W, vector<int>(H*W, INF));
  plot_maze(maze, dp);
  while (true) {
    bool is_update = false;
    for (auto i = 0;i < W*H;++i) {
      for (auto j = 0;j < W*H;++j) {
        for (auto k = 0;k < W*H;++k) {
          if (dp[i][j] > dp[i][k]+dp[k][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
            is_update = true;
          }
        }
      }
    }
    if (is_update == false) break;
  }
  int max_tmp {};
  for (const auto& e : dp) {
    for (const auto& f : e) {
      if (f == INF) continue;
      max_tmp = max(max_tmp, f);
    }
  }
  cout << max_tmp << '\n';
}
