#include <iostream>
#include <vector>

namespace prob30{
  unsigned long get_ans(const int& cards, const int& max_get, std::vector<std::vector<std::vector<unsigned>>>& memo) {
    memo[0][0][0] = 1;
    for (auto i = 1; i <= cards; ++i) {
      for (auto j = 1;j <= i;++j) {
        auto min_limit = (max_get < i)?max_get:i;
        for (auto k = 1;k <= min_limit;++k) {
          memo[0][i][j] += memo[1][i - k][i - j];
          memo[1][i][j] += memo[0][i - k][i - j];
        }
      }
    }
    unsigned long cnt {};
    for (auto i = cards; i > cards/2;--i) {
      if (memo[1][cards][i]) cnt += memo[1][cards][i];
    }
    return cnt;
  }
  unsigned long answer(const int& cards, const int& max_get) {
    std::vector<std::vector<std::vector<unsigned>>> memo;
    for (auto i = 0;i < 2;++i) { // 手番[0 or 1]
      std::vector<std::vector<unsigned>> tmp_memo(cards+1, std::vector<unsigned>(cards+1, 0));
      memo.push_back(tmp_memo);
    }
    return get_ans(cards, max_get, memo);
  }
}

int main(int argc, char** argv) {
  const int cards {32};
  const int max_get {10};
  std::cout << prob30::answer(cards, max_get) << '\n';
}
