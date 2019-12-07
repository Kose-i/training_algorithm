#include <iostream>
#include <vector>
#include <limits>

struct edge{
  int from;
  int to;
  int cost;
};
constexpr int INF {std::numeric_limits<int>::max()};

void answer(const int& N_node, const std::vector<edge>& vec_path) {
  std::vector<int> mincost(N_node, INF);
  std::vector<int> used(N_node, 0);
  std::vector<std::vector<int>> cost(N_node, std::vector<int>(N_node, INF));
  for (auto i = 0;i < N_node;++i) {
    cost[i][i] = 0;
  }
  for (auto& e : vec_path) {
    cost[e.from][e.to] = e.cost;
    cost[e.to][e.from] = e.cost;
  }
  mincost[0] = 0;
  int res {};
  std::vector<edge> min_tree;
  while (true) {
    int v = -1;
    for (auto u = 0;u < N_node;++u) {
      if (!used[u] && (v==-1 || mincost[u] < mincost[v])) v = u;
    }
    if (v==-1) break;
    used[v] = 1;
    res += mincost[v];
    for (auto u = 0;u < N_node;++u) {
      mincost[u] = (mincost[u]<cost[v][u])?mincost[u]:cost[v][u];
    }
  }
  std::cout << res << '\n';
}

int main(int argc, char** argv) {
  std::vector<edge> vec_path;
  edge tmp;
  tmp.from = 0;tmp.to = 1;tmp.cost = 2;
  vec_path.push_back(tmp);
  tmp.from = 0;tmp.to = 2;tmp.cost = 5;
  vec_path.push_back(tmp);
  tmp.from = 1;tmp.to = 2;tmp.cost = 4;
  vec_path.push_back(tmp);
  tmp.from = 2;tmp.to = 3;tmp.cost = 2;
  vec_path.push_back(tmp);
  tmp.from = 1;tmp.to = 3;tmp.cost = 6;
  vec_path.push_back(tmp);
  tmp.from = 1;tmp.to = 4;tmp.cost = 10;
  vec_path.push_back(tmp);
  tmp.from = 4;tmp.to = 5;tmp.cost = 3;
  vec_path.push_back(tmp);
  tmp.from = 3;tmp.to = 5;tmp.cost = 1;
  vec_path.push_back(tmp);
  tmp.from = 4;tmp.to = 6;tmp.cost = 5;
  vec_path.push_back(tmp);
  tmp.from = 5;tmp.to = 6;tmp.cost = 9;
  vec_path.push_back(tmp);

  answer(7, vec_path);
}
