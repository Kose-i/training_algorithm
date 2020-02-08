#include <vector>
#include <cmath>

struct edge{
  int to, cap, rev;
};

class FordFulkerson{
  private:
    constexpr static int INF {1000000000};
    std::vector<std::vector<edge>> G;
    std::vector<char> used;
  public:
    FordFulkerson(const int& N) : G(N, std::vector<edge>()), used(N, 0) {};
    void add_edge(const int from, const int to, const int cap) {
      edge e; e.to = to, e.cap = cap, e.rev = G[to].size();
      G[from].push_back(e);
      e.to = from, e.cap = cap, e.rev = G[from].size() - 1;
      G[to].push_back(e);
    }
    int dfs(const int v, const int t, const int f) {
      if (v == t) return f;
      used[v] = 1;
      for (auto i = 0;i < G[v].size(); ++i) {
        edge& e = G[v][i];
        if (used[e.to]==0 && e.cap>0) {
          int d = dfs(e.to, t, std::min(f, e.cap));
          if (d > 0) {
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }
    int max_flow(const int start, const int end) {
      int flow = 0;
      for (;;) {
        for (auto& e : used) e = 0;
        int f = dfs(start, end, INF);
        if (f == 0) return flow;
        flow += f;
      }
      return flow;
    }
};
