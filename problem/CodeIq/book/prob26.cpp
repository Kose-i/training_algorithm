#include <iostream>
#include <vector>

namespace prob26{
  const unsigned Ainitial {10};
  const unsigned Binitial {10};
  const unsigned FinishUpper {24};
  unsigned game(const unsigned& a, const unsigned& limit, std::vector<std::vector<unsigned>>& memo) {
    if (memo[a][limit]) return memo[a][limit];
    if ((a==0) || (a==Ainitial+Binitial)) return 1;
    if (limit == 0) return 0;
    unsigned cnt {};
    cnt += game(a+1, limit-1, memo);
    cnt += game(a, limit-1, memo);
    cnt += game(a-1, limit-1, memo);
    return memo[a][limit] = cnt;
  }
  unsigned answer() {
    std::vector<std::vector<unsigned>> memo(Ainitial+Binitial+1, std::vector<unsigned>(FinishUpper+1, 0));
    return game(Ainitial, FinishUpper, memo);
  }
}
int main(int argc, char** argv) {
  std::cout << prob26::answer() << '\n';
}
