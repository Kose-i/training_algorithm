#include <algorithm>
#include <iostream>
#include <vector>

unsigned answer(const int& size, const std::vector<unsigned>& vec) {
  std::vector<unsigned> sorted_vec = vec;
  std::sort(sorted_vec.begin(), sorted_vec.end());
  std::unique(sorted_vec.begin(), sorted_vec.end());
  unsigned max_pos {};
  unsigned max_ans = sorted_vec[sorted_vec.size() - 1];
  for (max_pos = 0;max_pos < size;++max_pos) {
    if (sorted_vec[max_pos] == max_ans) {
      break;
    }
  }
  return max_pos + 1;
}

int main(int argc, char** argv) {
  const int N {[](){int t;std::cin >> t;return t;}()};
  std::vector<unsigned> vec;
  for (auto i = 0;i < N;++i) {
    unsigned t;
    std::cin >> t;
    vec.push_back(t);
  }
  std::cout << answer(N, vec) << '\n';
}
