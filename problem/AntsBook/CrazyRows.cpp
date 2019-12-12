#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}
int answer(const int& N, const std::vector<std::vector<int>>& mat) {
  std::vector<int> array(N, 0);
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j < N;++j) {
      if (mat[i][j] == 1) array[i] = j;
    }
  }
  int res {};
  for (auto i = 0;i < N;++i) {
    int pos = -1;
    for (auto j = i;j < N;++j) {
      if (array[j] <= i) {
        pos = j;
        break;
      }
    }
    for (auto j = pos;j > i;--j) {
      swap(array[j], array[j - 1]);
      ++res;
    }
  }
  return res;
}
int main(int argc, char** argv) {
  const int N {4};
  std::vector<std::vector<int>> mat(N, std::vector<int>(N));
  mat[0][0] = 1; mat[0][1] = 1; mat[0][2] = 1; mat[0][3] = 0;
  mat[1][0] = 1; mat[1][1] = 1; mat[1][2] = 0; mat[1][3] = 0;
  mat[2][0] = 1; mat[2][1] = 1; mat[2][2] = 0; mat[2][3] = 0;
  mat[3][0] = 1; mat[3][1] = 0; mat[3][2] = 0; mat[3][3] = 0;
  std::cout << answer(N, mat) << '\n';
}
