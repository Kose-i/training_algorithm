#include <vector>
#include <utility>
#include <limits>
#include <queue>

struct edge{
  int from, to, cost;
};

using P = std::pair<int, int>;

class Dijkstra{
  private:
  constexpr static int INF {1000000000};
  std::vector<int> d;
  std::vector<std::vector<edge>> G;
  std::vector<int> prev;
  const int Node_size;
  const int Edge_size;
  public:
    Dijkstra(const int& N, const int& E, const std::vector<edge>& path_box) : d(N), G(N), prev(N), Node_size(N), Edge_size(E) {
      for (const auto& e : path_box) {
        G[e.from].push_back(e);
        edge E; E.from = e.to; E.to = e.to; E.cost = e.cost;
        G[e.to].push_back(E);
      }
    }
    int shortest_path(const int& start, const int& end) {
      for (auto i = 0;i < Node_size;++i) d[i] = INF;
      d[start] = 0;
      std::priority_queue<P, std::vector<P>, std::greater<P>> que;
      que.push(P(0, start));
      while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0;i < G[v].size(); ++i) {
          edge e = G[v][i];
          if (d[e.to] > d[v] + e.cost) {
            d[e.to] = d[v] + e.cost;
            que.push(P(d[e.to], e.to));
          }
        }
      }
      return d[end];
    }
    std::vector<int> get_path(const int& start, const int& t) {
      for (auto& e : prev) e = -1;
      std::vector<std::vector<int>> d_get_path(Node_size, std::vector<int>(Node_size, INF));
      std::vector<char> used(V, 0);
      d_get_path[start] = 0;
      while (true) {
        int v = -1;
        for (auto u = 0;u < V;++u) {
          if (used[u] ==0 && (v==-1||d_get_path[u]<d_get_path[v])) v = u;
        }
        if (v == -1) break;
        used[v] = 1;
        for (auto u = 0;u < V;++u) {
          if (d_get_path[u] > d_get_path[v] + G[v][u]) {
            d_get_path[u] = d_get_path[v] + G[v][u];
            prev[u] = v;
          }
        }
      }
      std::vector<int> path;
      for (; t != -1;t = prev[t]) path.push_back(t);
      std::reverse(path.begin(), path.end());
      return path;
    }
};
