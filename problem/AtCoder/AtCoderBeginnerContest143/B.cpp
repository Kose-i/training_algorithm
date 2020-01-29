#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> d(N);
  for (auto& e : d) std::cin >> e;
  long long sum {};
  for (auto i = 0;i < N;++i) {
    for (auto j = i+1;j < N;++j) {
      sum += d[i]*d[j];
    }
  }
  std::cout << sum << '\n';
}
