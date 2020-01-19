#include <iostream>
#include <vector>

unsigned long add_path(const int& start, const int& end, const int& N) {
  int tmp_N = N;
  int cnt {1};
  unsigned long sum {};

  return sum;
}
int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<std::vector<unsigned long>> dp(10, std::vector<unsigned long>(10, 0));
  //dp[i][j] : 先頭i最後j
  for (auto i = 1;i <= 9;++i) {
    for (auto j = 1;j <= 9;++j) {
      if (i==j) {//1桁
        if (N<i) break;
        dp[i][j] = 1;
      }
      dp[i][j] += add_path(i, j, N);
    }
  }
}
