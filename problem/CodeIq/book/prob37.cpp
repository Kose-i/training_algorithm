#include <iostream>
#include <vector>

namespace prob37{
  unsigned long search(const int& m, const int& n, std::vector<std::vector<unsigned long>>& memo) {
    if (n < 0) return 0;
    if (m==0) return (n==0)?1:0;
    if (memo[m][n]) return memo[m][n];
    unsigned long cnt {};
    for (auto i = 1;i <= 9;++i) {
      cnt += search(m-1, n-i, memo);
    }
    return memo[m][n] = cnt;
  }
  unsigned long answer(const int& keta, const int& memori) {
    std::vector<std::vector<unsigned long>> memo(keta+1, std::vector<unsigned long>(memori+1, 0));
    return search(keta, memori, memo);
  }
}

int main(int argc, char** argv) {
  const int ketasuu {10};
  const int memorisuu {50};
  std::cout << prob37::answer(ketasuu, memorisuu) << '\n';
}
