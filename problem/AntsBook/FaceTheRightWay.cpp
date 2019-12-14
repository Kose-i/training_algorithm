#include <iostream>
#include <string>
#include <vector>

int calc(const int& N, const std::string& S, const int& K) {
  std::vector<int> dir(N, 0);
  for (auto i = 0;i < N;++i) if (S[i] == 'B')dir[i] = 1;
  std::vector<int> dp(N, 0);
  int res {};
  int sum {};
  for (auto i = 0;i + K <= N;++i) {
    if ((dir[i] + sum)% 2 == 1) {
      ++res;
      dp[i] = 1;
    }
    sum += dp[i];
    if (i - K + 1 >= 0) {
      sum -= dp[i - K + 1];
    }
  }
  for (auto i = N - K + 1;i < N;++i) {
    if ((dir[i] + sum)%2 == 1) {
      return -1;
    }
    if (i - K + 1 >= 0) {
      sum -= dp[i - K + 1];
    }
  }
  return res;
}
void answer(const int& N, const std::string& S) {
  int K = 1, M = N;
  for (auto k = 1;k <= N;++k) {
    int m = calc(N, S, k);
    if (0 <= m && m < M) {
      M = m;
      K = k;
    }
  }
  std::cout << "K = " << K << '\n';
  std::cout << "M = " << M << '\n';
}
int main(int argc, char** argv) {
  const int N {7};
  std::string S {"BBFBFBB"};
  answer(N, S);
}
