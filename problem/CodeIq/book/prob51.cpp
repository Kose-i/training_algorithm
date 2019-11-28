#include <algorithm>
#include <iostream>
#include <vector>

namespace prob51{
  unsigned seq(const int& remain, std::vector<int>& used, const std::vector<int>& bits) {
    std::cout << used.size() << '\n';
    if (remain <= 1) return 1;
    unsigned cnt {};
    for (auto& e : bits) {
      if ((remain % e == 0) && (std::count(used.begin(), used.end(), 0) == 0)) {
        std::vector<int> used_map = used;
        std::for_each(used_map.begin(), used_map.end(), [&](auto& j){j=j^e;});
        used_map.push_back(e);
        cnt += seq(remain/e, used_map, bits);
      }
    }
    return cnt;
  }
  unsigned answer(const int& n) {
    std::vector<int>  used;
    std::vector<int> bits {0b0001, 0b0010, 0b0100, 0b0011, 0b1000, 0b0001}; // 2, 3, 5, 6, 7, 8
    return seq(n,used, bits);
  }
}

int main(int argc, char** argv) {
  const int n {1587600};
  std::cout << prob51::answer(n) << '\n';
}
