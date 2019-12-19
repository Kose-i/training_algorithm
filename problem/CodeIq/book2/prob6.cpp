#include <iostream>

namespace prob6{
  bool is_make_box(const unsigned& long_line, const unsigned& short_line, const unsigned& target_num) {
    if (target_num == 1 && long_line == short_line) {
      return true;
    } else if (target_num == 1) {
      return false;
    } else {
      unsigned surplus_long_line = std::max(long_line - short_line, short_line);
      unsigned surplus_short_line = std::min(long_line - short_line, short_line);
      return is_make_box(surplus_long_line, surplus_short_line, target_num - 1);
    }
  }
  unsigned answer() {
    unsigned ans_tmp {};
    for (auto long_line = 1000;0 < long_line;--long_line) {
      for (auto short_line = long_line - 1;0 < short_line;--short_line) {
        if ( is_make_box(long_line, short_line, 20) ) {
          ++ans_tmp;
        }
      }
    }
    return ans_tmp;
  }
}

int main(int argc, char** argv) {
  std::cout << prob6::answer() << '\n';
}
