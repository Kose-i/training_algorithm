#include <iostream>
#include <vector>

namespace prob27{
  unsigned long nCr(const unsigned& n, const unsigned& r, std::vector<std::vector<unsigned long>>& memo) {
    if (memo[n][r]) return memo[n][r];
    if ((r==0)||(r==n)) return 1;
    if (n<r) return 0;
    return memo[n][r] = nCr(n-1, r-1, memo) + nCr(n-1, r, memo);
  }
  unsigned long answer(const unsigned& line_masu, const unsigned& row_masu, const unsigned& people_count) {
    unsigned long cnt {};
    unsigned max_masu = (line_masu < row_masu)?row_masu:line_masu;
    std::vector<std::vector<unsigned long>> memo(max_masu+1, std::vector<unsigned long>(max_masu+1, 0));
    for (auto i = 0;i < people_count;++i) {
      unsigned j = people_count - 1 - i;
      //最後の積は”people_count = i + j”
      cnt += nCr(line_masu - 1, i, memo) * nCr(row_masu - 1, j, memo) * nCr(people_count - 1, i, memo);
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  const unsigned line_masu {20};
  const unsigned row_masu {20};
  const unsigned people_count {10};
  std::cout << prob27::answer(line_masu, row_masu, people_count) << '\n';
}
