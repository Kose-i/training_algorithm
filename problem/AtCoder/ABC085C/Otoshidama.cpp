#include <iostream>

void answer(const unsigned& N, const unsigned& Y) {
  if (10*N < Y) {
    std::cout << "-1 -1 -1\n";
    return;
  } else if (Y < N){
    std::cout << "-1 -1 -1\n";
    return;
  }
  unsigned ten_count{};
  unsigned five_count {N};
  unsigned one_count {};
  for (auto i = 0;i <= N; ++i) {
    unsigned tmp_money = ten_count*10 + five_count*5 + one_count;
    if (tmp_money < Y) {
      --five_count;
      ++ten_count;
    } else if (tmp_money > Y) {
      --five_count;
      ++one_count;
    } else {
      std::cout << ten_count << ' ' << five_count << ' ' << one_count << '\n';
      return;
    }
  }
  std::cout << "-1 -1 -1\n";
  return;
}
int main(int argc, char** argv) {
  const unsigned N {[](){unsigned t;std::cin >> t;return t;}()};
  const unsigned Y {[](){unsigned t;std::cin >> t;return t;}()};
  answer(N, Y/1000);
}
