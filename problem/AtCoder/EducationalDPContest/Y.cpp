#include <iostream>
#include <vector>

using ll = long long;

struct P{
  ll r, c;
};

int main(int argc, char** argv) {
  ll H, W, N;
  std::cin >> H >> W >> N;
  std::vector<P> Data(N);
  rep(i, N) std::cin >> Data[i].r >> Data[i].c;
}
