#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

#define rep(i,n) for(int i = 0;i < (n);++i)

struct P{
  ll x, y;
};

void dfs(int u, int p, std::vector<ll>& dp, std::vector<char>& visited, const std::vector<std::vector<int>>& Path) {
  visited[u] = 1;
  for (const auto v : Path[u]) {
    if (!visited[v]) dfs(v, u, dp, visited, Path);
    dp[u] = std::max(dp[u], 1 + dp[v]);
  }
}

int main(int argc, char** argv) {
  ll N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int>> Path(N+1, std::vector<int>());
  rep(i, M) {
    ll x, y;
    std::cin >> x >> y;
    Path[x].push_back(y);
  }
  std::vector<ll> dp(N+1, 0);
  std::vector<char> visited(N+1, 0);
  for (auto i = 1;i <= N;++i) {
    if (!visited[i]) dfs(i, 0, dp, visited, Path);
  }
  ll answer {};
  for (auto i = 1;i <= N;++i) {
    answer = std::max(answer, dp[i]);
  }
  std::cout << answer << '\n';
}
