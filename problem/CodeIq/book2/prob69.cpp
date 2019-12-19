#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using Pair = std::pair<int, int>;
namespace prob69{
  // split => {{3},{2,1}}
  std::vector<std::vector<int>> split(const int& n, const int& pre, std::map<Pair, std::vector<std::vector<int>> >& memo) {
    Pair t = {n, pre};
    if (memo.find(t) != memo.end()) return memo[t];
    std::vector<std::vector<int>> result;
    for (auto i = pre;i <= (n-1)/2; ++i) {
      Pair tmp {i, n-i};
      std::vector<std::vector<int>> temp_vec = split(n-1, i + 1, memo);
      result.insert(result.end(), temp_vec.begin(), temp_vec.end());
    }
    memo.insert(std::make_pair(t, result));
    return result;
  }
  unsigned search(std::vector<int>& used, const int& pos, std::map<Pair, std::vector<std::vector<int>> >& memo) {
    if (used.size() == pos) return 1;
    unsigned cnt = search(used, pos+1, memo);
    std::vector<std::vector<int>> vec = split(used[pos], 1, memo);
    std::for_each(vec.begin(), vec.end(), [&](auto& i) {
      bool flag = true;
      if (std::find(used.begin(), used.end(), i) != used.end()) {
        flag = false;
      }
      std::vector<int> new_used = used;
      new_used.insert(new_used.end(), i.begin(), i.end());
      if (flag) cnt += search(new_used, pos+1, memo);
    });
    return cnt;
  }
  unsigned answer(const int& N) {
    std::map<Pair, std::vector<std::vector<int>>> memo;
    std::vector<int> used(1,N);
    return search(used, 0, memo);
  }
}

int main(int argc, char** argv) {
  const int n {25};
  std::cout << prob69::answer(n) << '\n';
}
