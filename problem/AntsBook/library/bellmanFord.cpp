#include <vector>
#include <limits>

struct edge{
  int from, to, cost;
};

class BellmanFord{
  private:
  constexpr static int INF {1000000000};
  std::vector<int> d;
  std::vector<edge> es;
  const int Node_size;
  const int Edge_size;
  public:
    BellmanFord(const int& N, const int& E, const std::vector<edge>& path_box) : d(N), es(path_box), Node_size(N), Edge_size(E) {
//      es = path_box;
    }
    int shortest_path(const int& start, const int& end) {
      for (auto i = 0;i < Node_size;++i) d[i] = INF;
      d[start] = 0;
      while (true) {
        bool update = false;
        for (auto i = 0;i < Edge_size;++i) {
          edge e = es[i];
          if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
            d[e.to] = d[e.from] + e.cost;
            update = true;
          }
        }
        if (!update) break;
      }
      return d[end];
    }
    bool find_negative_loop() {
      for (auto i = 0;i < Node_size;++i) d[i] = 0;
      for (auto i = 0;i < Node_size;++i) {
        for (auto j = 0;j < Edge_size;++j) {
          edge e = es[j];
          if (d[e.to] > d[e.from] + e.cost) {
            d[e.to] = d[e.from] + e.cost;
            if (i == Node_size - 1) return true;
          }
        }
      }
      return false;
    }
};
