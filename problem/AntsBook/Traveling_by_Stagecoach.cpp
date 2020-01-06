#include <iostream>
#include <vector>

constexpr double INF {100000};
constexpr double min(double a, double b) {
  return (a < b)?a:b;
}

double answer(const int& N, const int& M, const int& a, const int& b, const std::vector<int>& t, const std::vector<std::vector<int>>& distance) {
  std::vector<std::vector<double>> dp(1<<N, std::vector<double>(M+1, INF));
  dp[(1<<N)-1][a-1] = 0;
  double res = INF;
  for (int S = (1<<N) - 1;S >= 0;--S) {
    res = min(res, dp[S][b-1]);
    for (int v = 0;v < M;++v) {
      for (int i = 0;i < N;++i) {
        if ((S>>i) &1) {
          for (int u  = 0;u < M;++u) {
            if (distance[v][u] >= 0) {
              dp[S&(~(1<<i))][u] = min(dp[S&(~(1<<i))][u], dp[S][v]+distance[v][u]/(double)t[i]);
            }
          }
        }
      }
    }
  }
  for (const auto& e : dp) {
    for (const auto& f : e) {
      std::cout << f << ' ';
    }
    std::cout << '\n';
  }
  if (res == INF) {
    return -1;
  } else {
    return res;
  }
}

int main(int argc, char** argv) {
  const int n {2};
  const int m {4};
  const int a {2};
  const int b {1};
  const std::vector<int> t {3, 1};
  std::vector<std::vector<int>> d(m+1, std::vector<int>(m+1, -1));
  //d[1][3] = 3; d[3][1] = 3;
  //d[1][4] = 2; d[4][1] = 2;
  //d[2][3] = 3; d[3][2] = 3;
  //d[2][4] = 5; d[4][2] = 5;
  d[0][2] = 3; d[2][0] = 3;
  d[0][3] = 2; d[3][0] = 2;
  d[1][2] = 3; d[2][1] = 3;
  d[1][3] = 5; d[3][1] = 5;
  std::cout << answer(n, m, a, b, t, d) << '\n';
}
