#include <iostream>
#include <vector>

namespace prob14{
  const int money{45678};
  const std::vector<int> money_chip= {10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1};
  unsigned re_answer(const int& now_money, const int& now_cnt, const int& chip_pos) {
    if (chip_pos == money_chip.size())return now_cnt;
    return re_answer(now_money%money_chip[chip_pos], now_cnt+now_money/money_chip[chip_pos], chip_pos+1);
  }
  unsigned answer(){
    return re_answer(money, 0, 0);
  }
}
int main(int argc, char** argv) {
  std::cout << prob14::answer() << '\n';
}
