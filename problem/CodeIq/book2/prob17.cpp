#include <iostream>
#include <vector>

namespace prob17{
  const unsigned N_people {32};
  const unsigned M_car {6};
  unsigned re_answer(std::vector<unsigned>& memo, int remain) {
    if (memo[remain]) return memo[remain];
    unsigned cnt = 0;
    for (auto i = 1; i <= M_car; ++i) {
      if (remain - i >= 0) cnt += re_answer(memo, remain - i);
    }
    return memo[remain] = cnt;
  }
  unsigned answer() {
    std::vector<unsigned> memo(32, 0);
    memo[0] = memo[1] = 1;
    return re_answer(memo, N_people);
  }
}

int main(int argc, char** argv) {
  std::cout << prob17::answer() << '\n';
}
