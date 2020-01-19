#include <iostream>
#include <vector>

struct Path{
  int a, b;
};
int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<Path> A(N);
  for (auto& e : A) {
    std::cin >> e.a >> e.b;
  }
  int M;
  std::cin >> M;
  std::vector<Path> B(M);
  for (auto& e : A) {
    std::cin >> e.a >> e.b;
  }
}
