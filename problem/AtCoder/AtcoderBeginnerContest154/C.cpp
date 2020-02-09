#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto& e : A) std::cin >> e;
  std::sort(A.begin(), A.end());
  for (auto i = 1;i < N;++i) {
    if (A[i] == A[i-1]) {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";
}
