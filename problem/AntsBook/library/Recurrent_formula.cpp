#include <vector>
#include <iostream>

class Recurrent_Formula{
  using mat = std::vector<std::vector<int>>;
  private:
    const int M;
    const int N;
    mat A;
    std::vector<int> initial;
  public:
    Recurrent_Formula(const int& n, const int& Mod, mat& m, const std::vector<int>& init) : A(m), initial(init), M(Mod), N(n) {}
    std::vector<int> answer(const int n) {
      mat B = pow(n);
      if (B[0].size() != initial.size()) {
        std::cerr << "B[0].size() != initial.size()\n";
        throw("size error");
      }
      std::vector<int> Ans(B.size(), 0);
      for (auto i = 0;i < B.size();++i) {
        for (auto j = 0;j < B[0].size();++j) {
          Ans[i] += B[i][j]*initial[j];
        }
      }
      return Ans;
    }
    mat pow(int n) {
      mat B(A.size(), std::vector<int>(A.size()));
      for (auto i = 0;i < A.size(); ++i) {
        B[i][i] = 1;
      }
      while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
      }
      return B;
    }
    mat mul(const mat& A, const mat& B) {
      mat C(A.size(), std::vector<int>(B.size()));
      for (auto i = 0;i < A.size(); ++i) {
        for (auto k = 0;k < B.size(); ++k) {
          for (auto j = 0;j < B[0].size(); ++j) {
            C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % M;
          }
        }
      }
      return C;
    }
};
