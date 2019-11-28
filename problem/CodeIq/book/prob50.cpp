#include <algorithm>
#include <iostream>
#include <vector>

namespace prob50{
  std::vector<int> check(std::vector<int>& used, const int& x) {
    std::vector<int> result;
    std::vector<int> temp = used;
    temp.push_back(0);
    for (auto i = 0;i < temp.size();++i) {
      if (std::count(temp.begin(), temp.end(), temp[i]+x) == 0) {
        result.push_back(temp[i]+x);
      } else {
        std::vector<int> null_vec;
        return null_vec;
      }
      result.push_back(temp[i]);
    }
    return result;
  }
  unsigned search(const int& n, const int& prev, std::vector<int>& used, const int& M, const int& N) {
    if (n == 0) return 1;
    unsigned cnt {};
    for (auto i = prev;i <= M;++i) {
      std::vector<int> next_used = check(used, i);
      if (next_used.size() != 0) cnt += search(n-1, i+1, next_used, M, N);
    }
    return cnt;
  }
  unsigned answer(const int& max_power, const int& monsters_count) {
    //std::vector<int> used(monsters_count+1, 0);
    std::vector<int> used;
    return search(monsters_count, 1, used, max_power, monsters_count);
  }
}

int main(int argc, char** argv) {
  const int max_power {50};
  const int monsters_count {4};
  std::cout << prob50::answer(max_power, monsters_count) << '\n';
}
