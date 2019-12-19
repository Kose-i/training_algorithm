#include <iostream>
#include <vector>

namespace prob30{
  unsigned long factorial(const unsigned& n) {
    unsigned long ans{1};
    for (auto i = 1;i <= n;++i) ans *= i;
    return ans;
  }

  unsigned long search(const int& cards, const int& pos, std::vector<std::vector<unsigned long>>& memo) {
    if (memo[cards][pos]) return memo[cards][pos];
    if (cards == 0) return 0;
    if (cards == pos -1) return factorial(cards) -1;
    unsigned long cnt = pos*search(cards-1, pos, memo);
    cnt += (cards - pos) * search(cards - 1, pos+1, memo);
    return memo[cards][pos] = cnt;
  }
  unsigned long answer(const int& number) {
    std::vector<std::vector<unsigned long>> memo(number+1, std::vector<unsigned long>(number+1,0));
    return search(number, 1, memo);
  }
}

int main(int argc, char** argv) {
  const int N {8};
  std::cout << prob30::answer(N) << '\n';
}
