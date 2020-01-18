#include <iostream>
#include <vector>

constexpr int max_problem {1000000000};

int main(int argc, char** argv) {
  int N, K, S;
  std::cin >> N >> K >> S;
  std::vector<int> A(N, S);
  int path_cnt = N - K;
  int tmp_t = (S!=max_problem)?1:-1;
  int path_check {};
  for (auto i = 0;i < N;++i) {
    if (path_check < path_cnt) {
      A[i] += tmp_t;
      ++path_check;
    } else {
      break;
    }
  }
  for (auto i = 0;i < N;++i) {
    std::cout << A[i];
    if (i == N-1) std::cout << '\n';
    else std::cout << ' ';
  }
}
