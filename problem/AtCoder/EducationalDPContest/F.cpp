#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string s_max(const std::string& l, const std::string& r) {
  if (l.size() > r.size()) return l;
  return r;
}
std::string s_max_triple(const std::string& l1, const std::string& l2, const std::string& l3) {
  return (s_max(l1, s_max(l2, l3)));
}

int main(int argc, char** argv) {
  std::string S, T;
  std::cin >> S >> T;
  int S_size = S.size();
  int T_size = T.size();
  std::vector<std::vector<int>> dp(S_size, std::vector<int>(T_size, 0));

  bool is_find = false;
  for (auto i = 0;i < S_size;++i) {
    if (is_find == true) {
      dp[i][0] = 1;
    } else if (is_find == false && S[i] == T[0]) {
      dp[i][0] = 1;
      is_find = true;
    }
  }
  is_find = false;
  for (auto i = 0;i < T_size;++i) {
    if (is_find == true) {
      dp[0][i] = 1;
    } else if (is_find == false && S[0] == T[i]) {
      dp[0][i] = 1;
      is_find = true;
    } else {
      dp[0][i] = 0;
    }
  }
  for (auto i = 1;i < S_size;++i) {
    for (auto j = 1;j < T_size;++j) {
      if (S[i] == T[j]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
    }
  }
  std::string answer {""};
  for (int x = S_size-1, y=T_size-1;x>=0 && y>=0;) {
    if (S[x] == T[y]) { // diag
      answer += S[x];
      --x; --y;
    } else if (x!=0 && dp[x][y] == dp[x-1][y]) { //line
        --x;
    } else { //column
        --y;
    }
  }
//  std::cout << answer << '\n';
  std::reverse(answer.begin(), answer.end());
  std::cout << answer << '\n';
//  for (const auto& e : dp) {
//    for (const auto& f : e) {
//      std::cout << f.size() << ' ';
//    }
//    std::cout << '\n';
//  }
}
