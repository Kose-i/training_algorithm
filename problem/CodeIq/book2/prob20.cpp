#include <iostream>

namespace prob20{
  const unsigned N {15};
  const unsigned start_pos {3};
  const unsigned end_pos {10};
  unsigned count(unsigned back_cnt, unsigned forward_cnt) {
    if (forward_cnt == 0) return 1;
    return 1 + forward_cnt*count(forward_cnt - 1, back_cnt);
  }
  unsigned answer() {
    if (start_pos == end_pos) {
      return 1;
    } else if (start_pos < end_pos) {
      return count(end_pos - 2, N - end_pos);
    } else {
      return count(N - end_pos - 1, end_pos - 1);
    }
  }
}

int main(int argc, char** argv) {
  std::cout << prob20::answer() << '\n';
}
