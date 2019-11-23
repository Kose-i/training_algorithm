#include <iostream>
#include <vector>

namespace prob24{
  const unsigned row_size{12};
  unsigned duo_search(const int& n, std::vector<unsigned>& duo_memo) {
    if (n < 0) return 0;
    if (duo_memo[n]) return duo_memo[n];
    return duo_memo[n] = duo_search(n - 1, duo_memo) * 2 + duo_search(n - 2, duo_memo);
  }
  unsigned trio_search(const int& n, std::vector<unsigned>& trio_memo) {
    if (n < 0) return 0;
    if (trio_memo[n]) return trio_memo[n];
    return trio_memo[n] = trio_search(n - 1, trio_memo) * 4 + trio_search(n - 2, trio_memo);
  }
  unsigned search(const int& n, std::vector<unsigned>& memo, std::vector<unsigned>& duo_memo, std::vector<unsigned>& trio_memo) {
    if (n < 0) return 0;
    if (memo[n]) return memo[n];
    unsigned sum = duo_search(n, duo_memo) * trio_search(n, trio_memo);
    for (auto i = 0;i < n;++i) {
      sum += duo_search(i, duo_memo) * trio_search(i, trio_memo) * search(n - i - 1, memo, duo_memo, trio_memo);
    }
    return memo[n] = sum;
  }
  unsigned answer() {
    std::vector<unsigned> memo(row_size+1, 0);
    std::vector<unsigned> duo_memo(row_size+1, 0);
    std::vector<unsigned> trio_memo(row_size+1, 0);
    duo_memo[0] = 1;
    trio_memo[0] = 1;
    return search(row_size, memo, duo_memo, trio_memo);
  }
}

int main(int argc, char** argv) {
  std::cout << prob24::answer() << '\n';
}
