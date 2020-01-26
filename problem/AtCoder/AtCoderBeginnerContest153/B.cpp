#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  unsigned long H, N;
  std::cin >> H >> N;
  std::vector<unsigned long> A(N);
  for (auto& e : A) std::cin >> e;
  unsigned long sum {};
  for (const auto& e : A) {
    sum += e;
  }
  std::cout << ((sum < H)?"No":"Yes") << '\n';
}
