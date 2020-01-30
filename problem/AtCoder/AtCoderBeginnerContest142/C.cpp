#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using P = std::pair<unsigned, int>;

int main(int argc, char** argv) {
  unsigned N;
  std::cin >> N;
  std::vector<P> A(N);
  for (auto i = 0;i < N;++i) {
    std::cin >> A[i].first;
    A[i].second = i+1;
  }
  std::sort(A.begin(), A.end());
  bool is_top = true;
  for (auto& e : A) {
    if (is_top == false) std::cout << ' ';
    std::cout << e.second;
    is_top = false;
  }
  std::cout << '\n';
}
