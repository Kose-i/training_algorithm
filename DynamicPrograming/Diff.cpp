#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

constexpr int INF {1000000};
constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
int answer(const std::string& s1, const std::string& s2) {
  int s1_size = s1.size();
  int s2_size = s2.size();
  std::vector<std::vector<int>> dp_map(s2_size+1, std::vector<int>(s1_size+1, INF));
  for (auto i = 0;i <= s1_size;++i) {
    dp_map[0][i] = i;
  }
  for (auto i = 0;i <= s2_size;++i) {
    dp_map[i][0] = i;
  }

  for (auto i = 1;i <=s2_size;++i) {
    bool find = false;
    for (auto j = 1;j <= s1_size;++j) {
      if (find == false && s2[i-1]==s1[j-1]) {
        dp_map[i][j] = min(min(dp_map[i][j-1]+1, dp_map[i-1][j]+1), dp_map[i-1][j-1]+1) - 1;
        find = true;
      } else {
        dp_map[i][j] = min(min(dp_map[i][j-1]+1, dp_map[i-1][j]+1), dp_map[i-1][j-1]+1);
      }
    }
  }

  for (auto i = 0;i <= s2_size;++i) {
    for (auto j = 0;j <= s1_size;++j) {
      std::cout << std::setw(2) << std::setfill(' ') << dp_map[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return dp_map[s2_size-1][s1_size-1];
}
int main(int argc, char** argv) {
  const std::string target2{"TAGATGGTCT"};
  const std::string target1{"TGGAGACAGTCT"};
  std::cout << answer(target1, target2) << '\n';
}
