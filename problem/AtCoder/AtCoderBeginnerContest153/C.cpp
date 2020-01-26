#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  unsigned long N, K;
  std::cin >> N >> K;
  std::vector<unsigned long> H(N);
  for (auto& e : H) std::cin >> e;
  std::sort(H.begin(), H.end(), std::greater<unsigned long>());
  unsigned long long sum {};
  for (auto i = 0;i < N;++i) {
    if (i < K) {
      ;
    } else {
      sum += H[i];
    }
  }
  std::cout << sum << '\n';
}
