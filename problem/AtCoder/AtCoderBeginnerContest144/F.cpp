#include <iostream>

struct P {
  int s, t;
};
int main(int argc, char** argv) {
  int N, M;
  std::cin >> N >> M;
  std::vector<P> A(M);
  for (auto& e : A) std::cin >> e.s >> e.t;
}
