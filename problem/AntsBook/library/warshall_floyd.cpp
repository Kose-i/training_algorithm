#include <vector>
#include <cmath>

struct edge{
  int from, to, cost;
};

class warshall_floyd {
  private:
    std::vector<std::vector<int>> d;
    const int Node_size;
  public:
    warshall_floyd(const int& V, const std::vector<edge>& path) : d(V, std::vector<int>(V)), Node_size(V) {
      for (const auto& e : path) {
        d[e.from][e.to] = e.cost;
        d[e.to][e.from] = e.cost;
      }
    }
    int shortest_path(const int& start, const int& end) {
      if (d[start][end] != -1) return d[start][end];
      for (auto i = 0;i < Node_size;++i) {
        for (auto j = 0;j < Node_size;++j) {
          for (auto k = 0;k < Node_size;++k) d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
        }
      }
      return d[start][end];
    }
};
