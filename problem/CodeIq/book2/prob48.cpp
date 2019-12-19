#include <iostream>
#include <vector>

namespace prob48{
  unsigned search(const int& n, std::vector<int> used, int sum, const int& card, const int& M, const int& N, const int& goal) {
//    for (const auto& e : used) {
//      std::cout << e;
//    }
//    std::cout << '\n';
    if (n == 1) return 1;

    unsigned cnt {};
    used[card] = 1;
    sum += card;
    if (sum == goal) {
      int max_non_used_card {M};
      for (auto i = M;i > 0;--i) {
        if (used[i] == 0) {
          max_non_used_card = i;
          break;
        }
      }
      cnt += search(n-1, used, 0, max_non_used_card, M, N, goal); // 次の人へ
    } else {
      int min_start = ((card-1)<(goal-sum))?(card-1):(goal-sum);
      for (auto i = min_start;i > 0;--i) {
        if (used[i] == 0) cnt += search(n, used, sum, i, M, N, goal);
      }
    }
    used[card] = 0;
    return cnt;
  }
  unsigned answer(const int& M, const int& N) {
    unsigned sum = M*(M+1)/2;
    unsigned each = sum/N;
    if (sum % N == 0) {
      std::vector<int> used(M+1, 0);
      return search(N, used, 0, M, M, N, each);
    } else {
      return 0;
    }
  }
}

int main(int argc, char** argv) {
  const int m {16};
  const int n {4};
  std::cout << prob48::answer(m, n) << '\n';
}
