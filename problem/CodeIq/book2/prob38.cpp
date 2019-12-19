#include <iostream>
#include <vector>

namespace prob38{
  unsigned long search(const int& n, const int& seat, const int& line, const int& row, std::vector<std::vector<unsigned long>>& memo) {
    if (n < 0) return 1;
    if (memo[n][seat]) return memo[n][seat];
    unsigned long cnt {};
    for (auto i = 0;i < line*row;++i) {
      if ((i/line != n/line) && (i%line != n%line)) {
        int t = 1<<i;
        if ((seat & (1<<i)) == 0) {
          cnt += search(n-1, seat | (1<<i), line, row, memo);
        }
      }
    }
    return memo[n][seat] = cnt;
  }
  unsigned long answer(const int& line, const int& row) {
    int chair_bits = 1<<(line*row);
    std::vector<std::vector<unsigned long>> memo(line*row+1, std::vector<unsigned long>(chair_bits+1, 0));
    return search(line*row - 1, 0, line, row, memo);
  }
}

int main(int argc, char** argv) {
  const int line {4};
  const int row  {4};
  std::cout << prob38::answer(line, row) << '\n';
}
