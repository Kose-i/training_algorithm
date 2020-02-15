#include <iostream>
#include <vector>

#define rep(i, n) for(int i = 0;i < (n);++i)
using ll = long long;

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<std::vector<ll>> a(N, std::vector<ll>(N));
  rep(i, N) rep(j, N) std::cin >> a[i][j];
}
