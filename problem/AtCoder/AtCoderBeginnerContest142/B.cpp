#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  unsigned N, K;
  std::cin >> N >> K;
  std::vector<int> H(N);
  for (auto& e : H) std::cin >> e;
  unsigned cnt {};
  for (auto& e : H) {
    if (e >= K) {
      ++cnt;
    }
  }
  std::cout << cnt << '\n';
}
