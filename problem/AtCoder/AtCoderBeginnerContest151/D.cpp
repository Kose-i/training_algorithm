#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>
//#include <iomanip> // BUILD

int main(int argc, char** argv) {
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<char>> map(H, std::vector<char>(W));
  for (auto& e : map) {
    for (auto& f : e) {
      std::cin >> f;
    }
  }
  int node_cnt {H*W};
  std::vector<std::vector<int>> dp(node_cnt, std::vector<int>(node_cnt, std::numeric_limits<int>::max()));
  for (auto i = 0;i < H;++i) {
    for (auto j = 0;j < W;++j) {
      if (map[i][j] == '.') {
        if (i-1>=0 && map[i-1][j] == '.') {
          dp[W*i+j][W*(i-1)+j] = 1;
          dp[W*(i-1)+j][W*i+j] = 1;
        }
        if (i+1<H && map[i+1][j] == '.') {
          dp[W*i+j][W*(i+1)+j] = 1;
          dp[W*(i+1)+j][W*i+j] = 1;
        }
        if (j-1>=0 && map[i][j-1] == '.') {
          dp[W*i+j][W*i+(j-1)] = 1;
          dp[W*i+(j-1)][W*i+j] = 1;
        }
        if (j+1<W && map[i][j+1] == '.') {
          dp[W*i+j][W*i+(j+1)] = 1;
          dp[W*i+(j+1)][W*i+j] = 1;
        }
      } else {//map[i][j] == '#'
        for (auto k = 0;k < node_cnt;++k) dp[W*i+j][k] = -1;
        for (auto k = 0;k < node_cnt;++k) dp[k][W*i+j] = -1;
      }
    }
  }
  for (bool is_update = true;is_update == true;) {
    is_update = false;
    for (auto i = 0;i < node_cnt;++i) {
      for (auto j = 0;j < node_cnt;++j) {
        if (i == j) continue;
        if (dp[i][j] == -1) continue;
        for (auto k = 0;k < node_cnt;++k) {
          if (dp[i][k] == std::numeric_limits<int>::max() || dp[k][j] == std::numeric_limits<int>::max()) continue;
          if (dp[i][k] == -1 || dp[k][j] == -1) continue;
          if (dp[i][k] + dp[k][j] < dp[i][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
            is_update = true;
          }
        }
      }
    }
  }
  int max_turn {};
  for (const auto& e : dp) {
    for (const auto& f : e) {
      if (f != std::numeric_limits<int>::max() )max_turn = std::max(max_turn, f);
//      std::cout << std::setw(3) << std::setfill(' ') << ((f == std::numeric_limits<int>::max())?0:f) << ' ';
    }
//    std::cout << '\n';
  }
  std::cout << max_turn << '\n';
}
