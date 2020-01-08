#include <iostream>
#include <vector>

using vec = std::vector<int>;
using mat = std::vector<std::vector<int>>;
mat mul(const mat& A, const mat& B) {
  mat C(A.size(), std::vector<int>(B[0].size(), 0));
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
mat pow(const mat& B, const int& n) {
  int n_tmp = n;
  mat B_tmp = B;
  int B_size = B.size();
  mat C(B_size, vec(B_size, 0));
  for (auto i = 0;i < B_size;++i) C[i][i] = 1;

  while (n_tmp > 0) {
    if (n_tmp&1) C = mul(C, B_tmp);
    B_tmp = mul(B_tmp, B_tmp);
    n_tmp >>= 1;
  }
  return C;
}
void answer(const int& n, const int& k, const int& M, const mat& A) {
  mat B(n*2, vec(n*2));
  for (auto i = 0;i < n;++i) {
    for (auto j = 0;j < n;++j) {
      B[i][j] = A[i][j];
    }
    B[n+i][i] = B[n+i][n+i] = 1;
  }
  B = pow(B, k+1);
  for (auto i = 0;i < n;++i) {
    for (auto j = 0;j < n;++j) {
      int a = B[n+i][j] % M;
      if (i == j) a = (a+M-1)%M;
      std::cout << a << ((j+1==n)?'\n':' ');
    }
  }
}

int main(int argc, char** argv) {
  const int n {2};
  const int k {2};
  const int M {4};
  const mat A{{0, 1}, {1, 1}};
  answer(n, k, M, A);
}
