#include <algorithm>
#include <iostream>
#include <vector>

namespace tmp{
  unsigned count(const unsigned& vec_size, const std::vector<unsigned>& vec) {
    unsigned t_min{};
    {
      unsigned t {vec[0]};
      for (;t % 2 == 0;++t_min) t /= 2;
    }
    for (auto i = 1;i < vec_size;++i) {
      unsigned t {vec[i]};
      unsigned cnt {};
      for (cnt = 0; cnt != t_min && t % 2 == 0; ++cnt) t /= 2;
      if (cnt < t_min) t_min = cnt;
    }
    return t_min;
  }
}

int main(int argc, char** argv) {
  const int N{[](){int t;std::cin >> t;return t;}()};
  std::vector<unsigned> A;
  for (auto i = 0;i < N;++i) {
    unsigned t;
    std::cin >> t;
    A.push_back(t);
  }
  std::cout << tmp::count(N, A) << '\n';
}
