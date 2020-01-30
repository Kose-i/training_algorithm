#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(M);
  std::vector<std::vector<int>> key_map(M, std::vector<int>(N,0));
  for (auto i = 0;i < M;++i) {
    std::cin >> A[i];
    int tmp;
    std::cin >> tmp;
    for (auto k = 0;k < tmp;++k) {
      int map_index;
      std::cin >> map_index;
      key_map[i][map_index - 1] = 1;
    }
  }
  std::vector<unsigned long long> sum_vec(M, 0);
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j < M;++j) {
      sum_vec[i] += key_map[j][i];
    }
    if (sum_vec[i] == 0) {
      std::cout << "-1\n";
      return 0;
    }
  }

  unsigned long long min_cost {};
  for (auto i = 0;i < M;++i) {
    min_cost += A[i];
  }
}
