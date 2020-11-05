#include <iostream>
#include <vector>

const std::vector<int> european {
  0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36,
  11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9,
  22, 18, 29, 7, 28, 12, 35, 3, 26
};
const std::vector<int> american {
  0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15,
  3, 24, 36, 13, 1, 00, 27, 10, 25, 29, 12, 8, 19, 31,
  18, 6, 21, 33, 16, 4, 23, 35, 14, 2
};

constexpr int max(int a, int b) {
  return ((a < b)?b:a);
}

int main(int argc, char** argv) {

  int size = european.size();

  std::vector<int> european_dp(size*2+1, 0);
  for (auto i = 0;i < size;++i) european_dp[i+1] = european_dp[i] + european[i];
  for (auto i = 0;i < size;++i) european_dp[i+size+1] = european_dp[i+size] + european[i];

  int american_size = american.size();
  std::vector<int> american_dp(american_size*2+1, 0);
  for (auto i = 0;i < american_size;++i) american_dp[i+1] = american_dp[i] + american[i];
  for (auto i = 0;i < american_size;++i) american_dp[i+american_size+1] = american_dp[i+american_size] + american[i];

  int cnt {};

  for (auto n = 2;n <= 36;++n) {
    int max_european {};
    int max_american {};
    for (auto start = 0;start < size;++start) {
      max_european = max(max_european, european_dp[start+n] - european_dp[start]);
    }
    for (auto start = 0;start < american_size;++start) {
      max_american = max(max_american, american_dp[start+n] - american_dp[start]);
    }
    if (max_european < max_american) {
      ++cnt;
    }
    //std::cout << n << ' ' << max_european << ' ' << max_american << '\n';
  }
  std::cout << cnt << '\n';
}
