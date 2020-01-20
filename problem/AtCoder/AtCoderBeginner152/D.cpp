#include <iostream>
#include <vector>

int get_keta(unsigned t) {
  int ans {};
  for (ans = 0;t > 9;t/=10, ++ans);
  return (ans+1);
}
unsigned get_permu(const int& start, const int& end, const int& ketasuu, const int& N) {
  if (ketasuu == 1) {
    if (start != end) return 0;
    return (N<start)?0:1;
  }
  unsigned tmp_num {1};
  for (auto i = 1;i < ketasuu;++i) {
    tmp_num *= 10;
  }
  int N_cp = N - start*tmp_num - end;
  if (N_cp < 0) {
    return 0;
  } else if (N_cp > tmp_num) {
    tmp_num = 1;
    for (auto i = 0;i < ketasuu - 2;++i) {
      tmp_num *= 10;
    }
    return tmp_num;
  } else {
    return 1+(N_cp/10);
  }
}
int main(int argc, char** argv) {
  unsigned N;
  std::cin >> N;
  std::vector<std::vector<unsigned>> dp(10, std::vector<unsigned>(10, 0));
  int ketasuu = get_keta(N);
  for (auto i = 1;i <= ketasuu;++i) {
    for (auto j = 1;j <= 9;++j) {
      for (auto k = 1;k <= 9;++k) {
        dp[j][k] += get_permu(j, k, i, N);
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
