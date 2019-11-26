#include <iostream>
#include <vector>

namespace prob34{
  unsigned search(const int& bw, const int& fw, std::vector<std::vector<int>>& memo) {
    if (memo[bw][fw]) return memo[bw][fw];
    if (fw == 0) return 0;
    unsigned cnt {};
    for (auto i = 1;i <= fw;++i) {
      cnt += search(fw - i, bw + i - 1, memo);
    }
    return memo[bw][fw] = cnt;
  }
  unsigned answer(const int& size) {
    std::vector<std::vector<int>> memo(size+1, std::vector<int>(size+1, 0));
    memo[0][0] = 1;
    if (size % 2 == 0) {
      return (search(0, size -2, memo));
    } else {
      return 0;
    }
  }
}

int main(int argc, char** argv) {
  const int size{12};
  std::cout << prob34::answer(size) << '\n';
}
