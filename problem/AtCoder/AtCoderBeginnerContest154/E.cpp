
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<long>> memo(101, std::vector<long>(4, -1));
long nCr(const int& n, const int& r) {
  if (n <= 0 || r < 0) return 0;
  if (r == 1) return n;
  if (n == r) return 1;
  if (n < r) return 0;
  if (memo[n][r] != -1) return memo[n][r];
  return memo[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

unsigned long long answer(const int& num, const std::string& S, const int& K, const int& S_size) {
  if (K == 1) {
      if (S_size - num < 1) return 0;
      if (S[num] == '0') return answer(num+1, S, K, S_size);
      return (S_size - num - 1)*9 + (S[num]-'0');
  } else if (K == 2) {
      if (S_size - num < 2) return 0;
      if (S[num] == '0') return answer(num+1, S, K, S_size);
      return (nCr(S_size - num-1, 2)*81 + (S[num]-'0'-1)*9*nCr(S_size - num - 1, 1) + answer(num+1, S, K-1, S_size));
  } else { // K == 3
      if (S_size - num < 3) return 0;
      return (nCr(S_size - num-1, 3)*729 + (S[num]-'0'-1)*81*nCr(S_size-num-1, 2) + answer(num+1, S, K-1, S_size));
  }
}

int main(int argc, char** argv) {
  std::string N;
  int K;
  std::cin >> N >> K;

  std::cout << answer(0, N, K, N.size()) << '\n';
}
