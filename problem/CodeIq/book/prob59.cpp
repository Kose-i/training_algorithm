#include <cmath>
#include <iostream>
#include <vector>

namespace prob59{
  constexpr int abs(int a) {
    return ((a>0)?(a):(-a));
  }
  constexpr int max(int a, int b) {
    return (a>b)?a:b;
  }
  constexpr int min(int a, int b) {
    return (a<b)?a:b;
  }
  unsigned nCr(const int& n, const int& r, std::vector<std::vector<unsigned>>& memo) {
    if (memo[n][r]) return memo[n][r];
    if ((r==0)||(r==n)) return 1;
    return memo[n][r] = nCr(n-1, r-1, memo) + nCr(n-1, r, memo);
  }
  unsigned answer(const int& N, const int& A, const int& B) {
    std::vector<std::vector<unsigned>> memo(2*N, std::vector<unsigned>(N+1, 0));
    if ( max(A,B) > N) {
      if ( abs(A-B) > 2) return 0;
      else return (nCr(2*N-2, N-1, memo)*(std::pow(2, min(A,B) - N+1)));
    } else if ( max(A, B) == N) {
      if ( abs(A-B) == 1) return (nCr(2*N-2, N-1, memo));
      else return (nCr(A+B-1, min(A,B), memo));
    } else {
      return (nCr(A+B, A, memo));
    }
  }
}

int main(int argc, char** argv) {
  const int get_score {11};
  const int A_score {25};
  const int B_score {24};
  std::cout << prob59::answer(get_score, A_score, B_score) << '\n';
}
