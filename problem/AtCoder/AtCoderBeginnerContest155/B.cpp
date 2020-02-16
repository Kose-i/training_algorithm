#include <iostream>
#include <vector>

using ll = long long;

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto& e : A) std::cin >> e;
  bool is_denied = false;
  for (auto i = 0;i < N;++i) {
    if (A[i] % 2 == 0) {
      if (A[i] % 5 == 0 || A[i] % 3 == 0) {
        continue;
      } else {
        is_denied = true;
      }
    }
  }
  if (is_denied == false) {
    std::cout << "APPROVED\n";
  } else {
    std::cout << "DENIED\n";
  }
}
