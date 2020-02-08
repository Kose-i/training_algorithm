#include <vector>

struct edge{
  int from, to, cost;
};

class prim{
  private:
    std::vector<std::vector<int>> cost;
    std::vector<int> min_cost;
    std::vector<char> used;
    const int Node_size;
  public:
    prim(const int V, const std::vector<edge>& path) : cost(V, std::vector<int>(V, INF)), min_cost(V), used(V, 0), Node_size(V) {
      for (const auto& e : path) {
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = e.cost;
      }
    }
    int shortest_path(const int& start, const int& end) {
      for (auto i = 0;i < Node_size;++i) {
        min_cost[i] = INF;
        used[i] = 0;
      }
      min_cost[0] = 0;
      int res = 0;

      while (true) {
        int v = -1;
        for (auto u = 0;u < Node_size;++u) {
          if (used[u]==0 && (v==-1||min_cost[u]<min_cost[v])) v = u;
        }
        if (v == -1) break;
        used[v] = 1;
        res += min_cost[v];
        for (auto u = 0;u < Node_size;++u) min_cost[u] = std::min(min_cost[u], cost[v][u]);
      }
      return min_cost[u];
    }
};
