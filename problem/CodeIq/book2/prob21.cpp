#include <iostream>
#include <vector>

namespace prob21{
  const unsigned sum_page{180};
  const unsigned max_days{14};
  unsigned search(const unsigned& pages, const unsigned& day, std::vector<std::vector<int>>& memo) {
    if (memo[pages][day]) return memo[pages][day];

    if (day == 1) return 1;
    unsigned cnt {};
    unsigned oneday = ((pages - day*(day-1)/2)/day);
    for (auto i = 1;i <= oneday; ++i) {
      cnt += search(pages - i*day, day - 1, memo);
    }
    return memo[pages][day] = cnt;
  }
  unsigned answer() {
    std::vector<std::vector<int>> memo(sum_page+1, std::vector<int>(max_days+1, 0));
    unsigned cnt {};
    for (auto i = 1;i <= max_days;++i) {
      cnt += search(sum_page, i, memo);
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  std::cout << prob21::answer() << '\n';
}
