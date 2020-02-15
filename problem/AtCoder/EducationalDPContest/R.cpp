#include <iostream>
#include <vector>

#define rep(i, n) for(int i = 0;i < (n);++i)
using ll = long long;

int main(int argc, char** argv) {
  int N;
  std::string K;
  std::cin >> N >> K;
  std::vector<std::vector<int>> a(N, std::vector<int>(N));
  rep(i,N) rep(j,N) std::cin >> a[i][j];
}
