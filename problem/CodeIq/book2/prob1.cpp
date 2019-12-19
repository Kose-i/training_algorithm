#include <iostream>

namespace prob1{
  unsigned make_ans(const unsigned& max, const unsigned& two_sum) {
    std::cout << "max:" << max << ", two_sum:" << two_sum << '\n';
    unsigned two_sum_tmp {two_sum};
    int ans_add_tmp {};
    if (two_sum % 2 == 0) {
      two_sum_tmp += 2;
      ans_add_tmp += 1;
    } else {
      two_sum_tmp += 1;
    }
    if (max < two_sum / 2) {
      std::cout << "error\n";
      return ans_add_tmp;
    } else if (max <= two_sum) {
      std::cout << "max <= two_sum\n";
      return 2*(max - two_sum_tmp/2) + ans_add_tmp;
    } else {
      std::cout << "two_sum < max\n";
      return two_sum + 1;
    }
  }
  unsigned long answer(const unsigned& target) {
    unsigned tmp_target = target/3;
    ++tmp_target;
    if (target % 3 == 2) {
      ++tmp_target;
    }
    unsigned ans {};
    for (auto i = tmp_target;i <= target;++i) {
      ans += make_ans(i, target - i);
      std::cout << i  << ':' << ans << '\n';
    }
    return ans*3;
  }
}
int main(int argc, char** argv) {
  const unsigned target = 100;
  std::cout << prob1::answer(target) << '\n';
}
