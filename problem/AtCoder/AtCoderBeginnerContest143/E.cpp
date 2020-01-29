#include <iostream>
#include <vector>

struct P {
  int A, B;
  int C;
};
struct Q{
  int s,t;
};

constexpr unsigned long INF{1000000000000000};

int main(int argc, char** argv) {
  int N, M;
  std::cin >> N >> M;
  unsigned long L;
  std::cin >> L;
  std::vector<P> path(M);
  for (auto& e : path) std::cin >> e.A >> e.B >> e.C;
  int Query_cnt {};
  std::cin >> Query_cnt;
  std::vector<Q> query(Query_cnt);
  for (auto& e : query) std::cin >> e.s >> e.t;

  std::vector<std::vector<unsigned long>> dp(N, std::vector<unsigned long>(N, INF));
  for (const auto& e : path) {
    dp[e.A-1][e.B-1] = e.C;
    dp[e.B-1][e.A-1] = e.C;
    if (e.C > L) dp[e.A-1][e.B-1] = INF;
    if (e.C > L) dp[e.B-1][e.A-1] = INF;
  }

  for (bool is_update = true;is_update == true;) {
    is_update = false;
    for (auto i = 0;i < N;++i) {
      for (auto j = i+1;j < N;++j) {
        for (auto k = 0;k < N;++k) {
          if (dp[i][k] == -1 || dp[k][j] == -1) continue;
          if (dp[i][j] > dp[i][k] + dp[k][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
            dp[j][i] = dp[i][j];
            is_update = true;
          }
        }
      }
    }
  }
  std::vector<std::vector<unsigned long>> cnt_dp(N, std::vector<unsigned long>(100000, INF));
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j < N;++j) {
      if (dp[i][j] <= L) cnt_dp[i][j] = 1;
    }
  }
  for (bool is_update = true;is_update == true;) {
    is_update = false;
    for (auto i = 0;i < N;++i) {
      for (auto j = i+1;j < N;++j) {
        for (auto k = 0;k < N;++k) {
          if (cnt_dp[i][j] > cnt_dp[i][k] + cnt_dp[k][j]) {
            cnt_dp[i][j] = cnt_dp[i][k] + cnt_dp[k][j];
            cnt_dp[j][i] = cnt_dp[i][j];
            is_update = true;
          }
        }
      }
    }
  }

  for (const auto& e : query) {
    if (dp[e.s][e.t] > 0) std::cout << cnt_dp[e.s][e.t] << '\n';
    else std::cout << "-1\n";
  }

}
