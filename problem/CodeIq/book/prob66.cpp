#include <iostream>
#include <vector>

namespace prob66{
  unsigned split(const int& m, const int& k, std::vector<std::vector<unsigned>>& memo) {
    if (memo[m][k]) return memo[m][k];
    if ((m==1) || (m==k)) return 1;
    if (k < m) return 0;
    return memo[m][k] = split(m-1, k-1, memo) + split(m, k-m, memo);
  }
  unsigned answer(const int& M, const int& N) {
    unsigned cnt {};
    std::vector<std::vector<unsigned>> memo(N, std::vector<unsigned>(N, 0));
    for (auto k = 1;k <= N/M;++k) {
      if ((N-k)%k == 0) cnt += split(M-1, (N-k)/k, memo);
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  const int candidate{20};
  const int vote_people{100};
  std::cout << prob66::answer(candidate, vote_people) << '\n';
}
