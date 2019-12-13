#include <algorithm>
#include <iostream>
#include <vector>

bool C(const int& N, const int& M, const std::vector<unsigned long>& X, const int& d) {
  int last {};
  for (auto i = 1;i < M;++i) {
    int crt = last + 1;
    while (crt < N && X[crt] - X[last] < d) ++crt;
    if (crt == N) return false;
    last = crt;
  }
  return true;
}
int answer(const int& N, const int& M, const std::vector<unsigned long>& X) {
  int left = 0, right = N;
  std::vector<unsigned long> X_copy = X;
  std::sort(X_copy.begin(), X_copy.end());
  while (right - left > 1) {
    int mid = (right + left)/2;
    if (C(N, M, X_copy, mid)) left = mid;
    else right = mid;
  }
  return left;
}
int main(int argc, char** argv) {
  const int N {5};
  const int M {3};
  std::vector<unsigned long> X {1, 2, 8, 4, 9};
  std::cout << answer(N, M, X) << '\n';
}
