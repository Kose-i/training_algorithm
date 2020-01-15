#include <iostream>
#include <vector>
#include <bitset>

constexpr int upper_limit{80*160};
constexpr int abs(int a) {
  return (a<0)?-a:a;
}
int main(int argc, char** argv) {
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int>> A(H, std::vector<int>(W));
  std::vector<std::vector<int>> B(H, std::vector<int>(W));
  for (auto& e : A) {
    for (auto& f : e) {
      std::cin >> f;
    }
  }
  for (auto& e : B) {
    for (auto& f : e) {
      std::cin >> f;
    }
  }
  std::vector<std::vector<std::bitset<upper_limit>>> dp(H, std::vector<std::bitset<upper_limit>>(W));
  dp[0][0][abs(A[0][0] - B[0][0])] = true;
  for (auto i = 0;i < H;++i) {
    for (auto j = 0;j < W;++j) {
      int C = abs(A[i][j] - B[i][j]);
      for (auto k = 0;k < upper_limit;++k) {
        if (i != 0) {
          if (abs(k+C)<upper_limit) {
            dp[i][j][abs(k+C)] = dp[i][j][abs(k+C)] | dp[i-1][j][k];
          }
          if (abs(k-C)<upper_limit) {
            dp[i][j][abs(k-C)] = dp[i][j][abs(k-C)] | dp[i-1][j][k];
          }
        }
        if (j != 0) {
          if (abs(k+C)<upper_limit) {
            dp[i][j][abs(k+C)] = dp[i][j][abs(k+C)] | dp[i][j-1][k];
          }
          if (abs(k-C)<upper_limit) {
            dp[i][j][abs(k-C)] = dp[i][j][abs(k-C)] | dp[i][j-1][k];
          }
        }
      }
    }
  }
  for (auto i = 0;i < upper_limit;++i) {
    if (dp[H-1][W-1][i] == true) {
      std::cout << i << '\n';
      return 0;
    }
  }
}
