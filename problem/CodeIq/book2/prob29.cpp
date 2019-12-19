#include <iostream>
#include <vector>

namespace prob29{
  unsigned long factorial(const int& t, std::vector<unsigned long>& fac_memo) {
    if (fac_memo[t]) return fac_memo[t];
    return fac_memo[t] = factorial(t-1, fac_memo)*t;
  }
  unsigned long cut(const int& m, const int& n, const int& len, const unsigned long& x, std::vector<unsigned long>& fac_memo) {
    if (len == 0) return x/ factorial(m+1, fac_memo);
    unsigned long cnt {};
    int max_len = (0 > (n-m*(len-1))?0:(n-m*(len-1)));
    for (int i = max_len;i <= n / len;++i) {
      cnt += cut(m-i, n-i*len, len-1, x/factorial(i, fac_memo), fac_memo);
    }
    return cnt;
  }
  unsigned long answer(const int& M, const int& N, const int& W) {
    unsigned long cnt {};
    std::vector<unsigned long> fac_memo(M+1, 0);
    fac_memo[0] = 1;
    for (int i = 0;i <= N/M;++i) {
      cnt += cut(M - 1, N - i*M, W, factorial(M, fac_memo), fac_memo);
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  const int m {20};
  const int n {40};
  const int w {10};
  std::cout << prob29::answer(m, n, w) << '\n';
}
