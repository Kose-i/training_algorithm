#include <iostream>

struct P{
  int from, to, cost;
};
int main(int argc, char** argv) {
  int N, M, K, D;
  std::cin >> N >> M >> K >> D;
  std::vector<int> a(N);
  for (auto& e : a) std::cin >> e;
  std::vector<P> path(M);
  for (auto& e : path) std::cin >> e.from >> e.to >> e.cost;
}
998244353
