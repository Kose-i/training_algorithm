#include <iostream>
#include <vector>

namespace prob61{
  unsigned long answer(const int& N) {
    std::vector<std::vector<unsigned long>> z(N+1, std::vector<unsigned long>(N+1, 0));
    z[0][0] = 1;
    for (auto n = 1;n <= N;++n) {
      for (auto k = 1;k <= n;++k) {
        z[n][k] = z[n][k-1] + z[n-1][n-k];
      }
    }
    return 2*z[N][N];
  }
}

int main(int argc, char** argv) {
  const int N {20};
  std::cout << prob61::answer(N) << '\n';
}
