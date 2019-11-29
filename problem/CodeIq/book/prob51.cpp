#include <algorithm>
#include <iostream>
#include <vector>

namespace prob51{
  unsigned seq(const int& remain, const std::vector<int>& used, const std::vector<std::vector<int>>& bits) {
    if (remain <= 1) return 1;
    unsigned cnt {};
    for (const auto& e : bits) {
      if ((remain % e[0] == 0) && (std::count(used.begin(), used.end(), 0) == 0)) {
        std::vector<int> used_map = used;
        std::for_each(used_map.begin(), used_map.end(), [&](auto& j){j=j^e[1];});
        used_map.push_back(e[1]);
        cnt += seq(remain/e[0], used_map, bits);
      }
    }
    return cnt;
  }
  unsigned answer(const int& n) {
    std::vector<int>  used;
    std::vector<std::vector<int>> bits {{2, 0b0001},{3, 0b0010},{5, 0b0100},{6, 0b0011}, {7,0b1000},{8, 0b0001}};
    return seq(n,used, bits);
  }
}

int main(int argc, char** argv) {
  const int n {1587600};
  //const int n {15};
  std::cout << prob51::answer(n) << '\n';
}
