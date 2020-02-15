#include <iostream>
#include <vector>
#include <cmath>
 
int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<long long> H(N);
  for (auto& e : H) std::cin >> e;
  std::vector<long long> Sum_H(N);
  Sum_H[1] = std::abs(H[1] - H[0]);
  for (auto i = 2;i < N;++i) {
    Sum_H[i] = std::min(Sum_H[i-1] + std::abs(H[i] - H[i-1]), Sum_H[i-2] + std::abs(H[i] - H[i-2]));
  }
  std::cout << Sum_H[N-1] << '\n';
}
