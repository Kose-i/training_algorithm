#include <iostream>
#include <vector>

namespace prob28{
  unsigned long calc(const std::vector<unsigned>& log) {
    unsigned long result {1};
    unsigned n {};
    auto log_size = log.size(); // 6
    for (auto i = 1;i < log_size; ++i) {
      n += log[i]; //18 -1
    }
    for (auto i = 1;i <= n;++i) {
      result *= i; // 17!
    }
    for (auto i = 1;i < log_size;++i) {
      auto div = 1;
      for (auto j = 1;j <= log[i];++j) {
        div *= j; // n!
      }
      result /= div;
    }
    return result; // 17! / (a!b!c!d!e!)
  }
  unsigned long golf(const int& hole, const int& par, std::vector<unsigned>& log) {
    if ((hole <= 0) || (par <= 0)) return 0;
    if ((hole == 1) && (par <= 5)) return calc(log);
    unsigned long cnt {};
    for (auto i = 5;1 <= i;--i) {
      log[i] += 1;
      cnt += golf(hole - 1, par-i, log);
      log[i] -= 1;
      if (log[i] > 0) break;
    }
    return cnt;
  }
  unsigned long answer(const int& hole_size, const int& par_size) {
    std::vector<unsigned> vec(6,0);
    return golf(hole_size, par_size, vec);
  }
}

int main(int argc, char** argv) {
  const int Pole_size{18};
  const int Par_size {72};
  std::cout << prob28::answer(Pole_size, Par_size) << '\n';
}
