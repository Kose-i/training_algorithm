#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

struct Node_Status{
  int have_money;
  int time_now;
};
struct Path{
  int cost_money;
  int cost_time;
};
constexpr int cost_time_INF {100000000};

int answer(const int& country_size, const int& max_money, const int& path_size, const std::vector<int>& from_path, const std::vector<int>& to_path, const std::vector<int>& cost, const std::vector<int>& time) {

  std::vector<std::vector<int>> dp(country_size, std::vector<int>(country_size, 0));
  for (auto i = 0;i < path_size;++i) {
    dp[from_path[i] - 1][to_path[i] - 1] = cost[i];
  }
  for (auto i = 0;i < country_size;++i) {
    for (auto j = 0;j < country_size;++j) {
      for (auto k = 0;k < country_size;++k) {
        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  if (max_money < dp[0][country_size-1]) {
    return -1;
  }
  return dp[0][country_size-1];
}
int main(int argc, char** argv) {
  int N, C, V;
  std::cin >> N >> C >> V;
  std::vector<int> from(V);
  for (auto& e : from) {std::cin >> e;}
  std::vector<int> to(V);
  for (auto& e : to) {std::cin >> e;}
  std::vector<int> cost(V);
  for (auto& e : cost) {std::cin >> e;}
  std::vector<int> time(V);
  for (auto& e : time) {std::cin >> e;}
  std::cout << answer(N, C, V, from, to, cost, time) << '\n';
}
