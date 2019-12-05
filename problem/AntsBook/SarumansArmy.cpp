#include <algorithm>
#include <iostream>
#include <vector>

int answer(const int& N, const int& R, const std::vector<int>& X) {
  std::vector<int> sorted_X = X;
  std::sort(sorted_X.begin(), sorted_X.end());
  for (auto e : sorted_X) {
    std::cout  << e << ' ';
  }
  std::cout << '\n';
  int answer_cnt {};
  for (auto i = 0;i < N;) {
    int s = X[i];
    ++i;
    std::cout << s << '\n';
    while (i < N && X[i] <= s+R) ++i;
    int p = X[i-1];
    std::cout << p << '\n';
    while (i < N && X[i] <= p+R) ++i;
    ++answer_cnt;
  }
  return answer_cnt;
}

int main(int argc, char** argv) {
  int N {},R {};
  std::cin >> N >> R;
  std::vector<int> X(N);
  for (auto& e : X) {
    std::cin >> e;
  }
  std::cout << answer(N, R, X) << '\n';
}
