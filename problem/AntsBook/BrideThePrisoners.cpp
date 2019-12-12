#include <algorithm>
#include <iostream>
#include <vector>

constexpr int Int_max {500000};

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
int answer(const int& P, const int& Q, std::vector<int> A) {
  A.push_back(0); A.push_back(P+1);
  std::sort(A.begin(), A.end());
  std::vector<std::vector<int>> dp(Q+1, std::vector<int>(Q+2, Int_max));
  for (auto q = 0;q <= Q;++q) {
    dp[q][q+1] = 0;
  }
  for (auto w = 2;w <= Q+1;++w) {
    for (auto i = 0;i+w<=Q+1;++i) {
      int j = i+w, t = Int_max;
      for (auto k = i+1;k < j;++k) {
        t = min(t, dp[i][k] + dp[k][j]);
      }
      dp[i][j] = t+A[j] - A[i] - 2;
    }
  }
  return dp[0][Q+1];
}

int main(int argc, char** argv) {
  const int P {20};
  const int Q {3};
  const std::vector<int> A {3, 6, 14};
  std::cout << answer(P, Q, A) << '\n';
}
