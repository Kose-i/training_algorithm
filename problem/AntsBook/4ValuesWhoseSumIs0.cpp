#include <iostream>
#include <vector>
#include <algorithm>

int answer(const int& N, const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C, const std::vector<int>& D) {
  std::vector<int> AB(N*N);
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j < N;++j) {
      AB[N*i+j] = A[i]+B[j];
    }
  }
  std::sort(AB.begin(), AB.end());
  std::vector<int> CD(N*N);
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j < N;++j) {
      CD[N*i+j] = C[i]+D[j];
    }
  }
  std::sort(CD.begin(), CD.end());
  int CD_point = N*N-1;
  int res {};
  for (auto i = 0;i < N*N;++i) {
    while (AB[i] + CD[CD_point] > 0) {
      --CD_point;
    }
    if (AB[i] + CD[CD_point] == 0) ++res;
  }
  return res;
}

int main(int argc, char** argv) {
  const int n {6};
  const std::vector<int> A{-45, -41, -36, -36,  26, -32};
  const std::vector<int> B{ 22, -27,  53,  30, -38, -54};
  const std::vector<int> C{ 42,  56, -37, -75, -10,  -6};
  const std::vector<int> D{-16,  30,  77, -46,  62,  45};
  std::cout << answer(n, A, B, C, D) << '\n';
}
