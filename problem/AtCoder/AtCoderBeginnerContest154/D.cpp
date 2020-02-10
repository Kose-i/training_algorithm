#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
  int N, K;
  std::cin >> N >> K;
  std::vector<int> p(N);
  for (auto& e : p) std::cin >> e;
  std::vector<double> ave(N);
  for (auto i = 0;i < N;++i) {
    ave[i] = static_cast<double>(p[i]+1)/2;
  }
  double sum_tmp {};
  for (auto i = 0;i < K;++i) {
    sum_tmp += ave[i];
  }
  double sum_max = sum_tmp;
  for (auto i = K;i < N;++i) {
    sum_tmp += ave[i] - ave[i-K];
    sum_max = std::max(sum_max, sum_tmp);
  }
  std::cout << std::fixed << sum_max << '\n';
}
