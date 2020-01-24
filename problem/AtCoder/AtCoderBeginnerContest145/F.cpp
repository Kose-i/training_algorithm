#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int N, K;
  std::cin >> N;
  std::cin >> K;
  std::vector<unsigned long> H(N);
  for (auto& e : H) std::cin >> e;
}
