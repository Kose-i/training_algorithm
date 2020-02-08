#include <vector>

class BitDP{
  private:
    constexpr static int INF {1000000000};
    const int N;
    std::vector<std::vector<int>> d;
    std::vector<std::vector<int>> dp;
  public:
    BitDP(const int& n) : d(n, std::vector<int>(n)), dp(1<<n, std::vector<int>(n)), N(n) {}
    int rec(const int S, const int v) {
      if (dp[S][v] >= 0) {
        return dp[S][v];
      }
      if (S == (1<<N)-1 && v == 0) {
        return dp[S][v] = 0;
      }
      int res = INF;
      for (auto u = 0;u < N;++u) {
        if (!(S>>u & 1)) {
          res = std::min(res, rec(S|1<<u, u) + d[v][u]);
        }
      }
      return dp[S][v] = res;
    }
    int solve() {
      for (auto& e : dp) {
        for (auto& f : e) f = -1;
      }
      return rec(0, 0);
    }
};
