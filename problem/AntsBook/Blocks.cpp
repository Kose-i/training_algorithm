#include <iostream>
#include <vector>

std::vector<std::vector<int>> mul(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
  std::vector<std::vector<int>> C(A.size(), std::vector<int>(B[0].size(), 0));
  int A_size = A.size();
  int B_size = B.size();
  int B_zero_size = B[0].size();
  for (auto i = 0;i < A_size;++i) {
    for (auto j = 0;j < B_size;++j) {
      for (auto k = 0;k < B_zero_size;++k) {
        C[i][k] = (C[i][k] + A[i][j] * B[j][k]);
      }
    }
  }
  return C;
}
std::vector<std::vector<int>> pow(const std::vector<std::vector<int>>& A, const int& n) {
  int A_size = A.size();
  std::vector<std::vector<int>> B(A_size, std::vector<int>(A_size, 0));
  for (auto i = 0;i < A_size;++i) {
    B[i][i] = 1;
  }
  std::vector<std::vector<int>> A_temp = A;
  int n_temp = n;
  while (n_temp > 0) {
    if (n_temp & 1) B = mul(B, A_temp);
    A_temp = mul(A_temp, A_temp);
    n_temp >>= 1;
  }
  return B;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> A = {{2, 1, 0},{2, 2, 2}, {0, 1, 2}};
  const int N = 2;
  A = pow(A, N);
  std::cout << A[0][0] << '\n';
}
