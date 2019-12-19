#include <iostream>
#include <vector>

namespace prob35{
  unsigned long check(const int& bill, const int& remain, std::vector<std::vector<unsigned long>>& memo) {
    if (memo[bill][remain]) return memo[bill][remain];
    if (remain == 0) return 1;
    unsigned long cnt = check(bill + 3, remain - 1, memo);
    if (bill >= 2) {
      cnt += check(bill - 2, remain - 1, memo);
    }
    return memo[bill][remain] = cnt;
  }
  unsigned long answer(const int& people_count) {
    std::vector<std::vector<unsigned long>> memo(people_count*3+1, std::vector<unsigned long>(people_count+1, 0));
    return check(0, people_count, memo);
  }
}

int main(int argc, char** argv) {
  const int people_count {32};
  std::cout << prob35::answer(people_count) << '\n';
}
