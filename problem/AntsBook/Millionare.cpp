#include <iostream>
#include <vector>

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
constexpr double max(double a, double b) {
  return (a>b)?a:b;
}
void swap(double& t1, double& t2) {
  double tmp = t1;
  t1 = t2;
  t2 = tmp;
}
void swap(std::vector<double>& t1, std::vector<double>& t2) {
  int t1_size = t1.size();
  for (auto i = 0;i < t1_size;++i) {
    swap(t1[i], t2[i]);
  }
}
double answer(const int& M, const double& P, const int& X) {
  int search_size = (1<<M) + 1;
  std::vector<std::vector<double>> dp(2, std::vector<double>(search_size, 0));
  dp[0][search_size - 1] = 1.0;
  for (auto r = 0;r < M; ++r) {
    for (auto i = 0;i < search_size;++i) {
      int jub = min(i, search_size-1-i);
      double t = 0.0;
      for (auto j = 0;j <= jub;++j) {
        t = max(t, P*dp[0][i+j] + (1-P)*dp[0][i-j]);
      }
      dp[1][i] = t;
    }
    swap(dp[0], dp[1]);
  }
  int i = (long long)X*(search_size-1) / 1000000;
  return dp[0][i];
}

int main(int argc, char** argv) {
  const int M {3};
  const double P {0.75};
  const int X {600000};
  std::cout << answer(M, P, X) << '\n';
}
