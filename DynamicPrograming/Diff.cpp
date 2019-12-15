#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int answer(const std::string& s1, const std::string& s2) {
  int s1_size = s1.size();
  int s2_size = s2.size();
  std::vector<std::vector<int>> dp_map(s1_size, std::vector<int>(s2_size, 0));
  int k {};
  bool find = false;
  for (auto i = 0;i < s1_size;++i) {
    if (find == false && s1[i] == s2[0]) {
      if (i == 0) {
        dp_map[0][i] = 0;
      } else {
        dp_map[0][i] = dp_map[0][i-1];
      }
    }
  }
  for (auto i = 1;i < s1_size;++i) {
    for (auto j = 0;j < s2_size;++j) {
      if (s1[i] == s2[j] && find == false) {
        dp_map[i][j] = dp_map[i-1][j];
        find = false;
      } else {
        dp_map[i][j] = dp_map[i][j-1] + 1;
      }
    }
  }
  for (const auto& e : dp_map) {
    for (const auto& f : e) {
      std::cout << std::setw(2) << std::setfill(' ') << f << ' ';
    }
    std::cout << '\n';
  }

  return dp_map[s1_size][s2_size];
}
int main(int argc, char** argv) {
  const std::string target1{"TAGATGGTCT"};
  const std::string target2{"TGGAGACAGTCT"};
  std::cout << answer(target1, target2) << '\n';
}
