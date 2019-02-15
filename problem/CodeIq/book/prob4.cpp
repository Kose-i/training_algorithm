#include <iostream>
#include <vector>

namespace prob4{
  std::vector<unsigned> count_dem{6,2,5,5,4,5,6,3,7,6};
  unsigned combination(const unsigned& target) {
    unsigned ten_target = target / 10;
    unsigned one_target = target % 10;
    return (count_dem[ten_target] + count_dem[one_target]);
  }
  unsigned combination(const unsigned& target1, const unsigned& target2, const unsigned& target3) {
    return (combination(target1)+combination(target2)+combination(target3));
  }
  unsigned make_answer() {
    unsigned ans_tmp {};
    const unsigned target = 30;
    for (auto i = 0;i < 24;++i) {//時刻
      for (auto j = 0;j < 60;++j) {//分
        for (auto k = 0;k < 60;++k) {//秒
          if (combination(i, j, k) == target) {
            ++ans_tmp;
          }
        }
      }
    }
    return ans_tmp;
  }
  unsigned answer() {
    unsigned ans_tmp = prob4::make_answer();
    return ans_tmp;
  }
}
int main(int argc, char** argv) {
  std::cout << prob4::answer() << '\n';
}
