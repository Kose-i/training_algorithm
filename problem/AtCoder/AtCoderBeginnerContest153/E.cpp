#include <iostream>
#include <vector>

struct P {
  int A, B;
};
constexpr unsigned long long max_magic_power {100000000000};

unsigned long long min_ull(const unsigned long long a, const unsigned long long b) {
  return (a<b)?a:b;
}

int main(int argc, char** argv) {
  int H, N;
  std::cin >> H >> N;
  std::vector<P> magic_list(N);
  for (auto& e : magic_list) std::cin >> e.A >> e.B;
  std::vector<unsigned long long> dp(H+1, max_magic_power);
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j <= magic_list[i].A && (j < H+1);++j) {
      dp[j] = min_ull(dp[j], magic_list[i].B);
    }
  }
  for (auto is_update = true;is_update == true;) {
    is_update = false;
    for (auto i = 0;i < N;++i) {
      for (auto j = magic_list[i].A;j < H+1;++j) {
        if (magic_list[i].B + dp[j-magic_list[i].A] < dp[j]) {
          dp[j] = magic_list[i].B + dp[j-magic_list[i].A];
          is_update = true;
        }
      }
    }
  }
  std::cout << dp[H] << '\n';
}
