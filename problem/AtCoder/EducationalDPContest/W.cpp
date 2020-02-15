#include <iostream>
#include <vector>

using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);++i)

struct P{
  ll left, right;
  ll score;
}

int main(int argc, char** argv) {
  ll N, M;
  std::cin >> N >> M;
  std::vector<P> Data(M);
  rep(i, M) std::cin >> Data[i].left >> Data[i].right >> Data[i].score;
}
