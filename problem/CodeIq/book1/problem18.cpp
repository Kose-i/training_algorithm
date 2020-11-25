#include <iostream>
#include <vector>

bool check(const int& n, const int& last_num, std::vector<char>& used, const std::vector<std::vector<char>>& table) {
  for (auto i = 1;i <= n;++i) {
    if (used[i-1] == 0) break;
    if (i == n && table[last_num-1][1-1] == 1) return true;
  }
  bool ans {false};
  for (auto i = 2;i <= n;++i) {
    if (used[i-1] == 0 && table[last_num-1][i-1]==1) {
      used[i-1] = 1;
      ans = check(n, i, used, table);
      if (ans == true) return true;
      used[i-1] = 0;
    }
  }
  return ans;
}

int main(int argc, char** argv) {
  int n {2};
  for (;true;++n) {
    std::vector<char> used(n, 0);
    used[0] = 1;
    std::vector<char> vec(2*n+1, 0);
    for (auto i = 1;i*i <= 2*n;++i) {
      vec[i*i] = 1;
    }
    std::vector<std::vector<char>> table(n+1, std::vector<char>(n+1, 0));
    for (auto i = 1;i <= n;++i) {
      for (auto j = 1;j <= n;++j) {
        if (vec[i+j] == 1) {
          table[i-1][j-1] = 1;
        }
      }
    }
    if (check(n, 1, used, table)) break;
  }
  std::cout << n << '\n';
}
