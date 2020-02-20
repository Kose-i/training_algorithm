#include <iostream>
#include <vector>
#include <cmath>

using ull = unsigned long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ull> A(N);
  rep(i, N) std::cin >> A[i];
  std::vector<std::vector<ull>> dp(N, std::vector<ull>(N));
  for (auto i = N-1;i >= 0;--i) {
    for (auto j = N-1;j > i;--j) {
      ull sum_slime = std::accumulate(A.begin() + i, A.begin() + j);
    }
  }
}
