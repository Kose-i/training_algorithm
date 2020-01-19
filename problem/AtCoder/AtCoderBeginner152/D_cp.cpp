#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<std::vector<unsigned long>> dp(10, std::vector<unsigned long>(10, 0));
  //dp[i][j] : 先頭i最後j
  int keta {1};
  int tmp_keta {1};
  while (tmp_keta*10 < N) {
    tmp_keta *= 10;
    ++keta;
  }
  unsigned long t {1};
  for (auto k = 1;k < keta;++k) {
    for (auto i = 1;i <= 9;++i) {
      for (auto j = 1;j <= 9;++j) {
        dp[i][j] += t;
      }
    }
    t *= 10;
  }
  t *= 10;
  for (auto i = 1;;++i) {
    if ((i+1)*tmp_keta > N) {
      t = 1;
      N -= i*tmp_keta;
      while (N > 9) {
        int num {9};
        tmp_keta /= 10;
        while (num*tmp_keta > N) {
          --num;
        }
        t *= (num+1);
        N -= num*tmp_keta;
      }
      for (auto j = 1;j <= 9;++j) {
        dp[i][j] += (N>j)?t:(t-1);
      }
      break;
    } else {
      for (auto j = 1;j<=9;++j) {
        dp[i][j] += t;
      }
    }
  }
  unsigned long sum {};
  for (auto i = 1;i <= 9;++i) {
    for (auto j = 1;j <= 9;++j) {
      sum += dp[i][j]*dp[j][i];
    }
  }
  std::cout << sum << '\n';
}
