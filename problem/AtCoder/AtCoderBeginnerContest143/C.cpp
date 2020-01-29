#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  unsigned long N;
  std::cin >> N;
  std::vector<char> S(N);
  for (auto& e : S) std::cin >> e;
  unsigned long cnt {1};
  for (auto i = 1;i < N;++i) {
    if (S[i] != S[i-1]) ++cnt;
  }
  std::cout << cnt << '\n';
}
