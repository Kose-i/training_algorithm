#include <vector>
#include <algorithm>
#include "./UnionFind_tree.cpp"

struct edge{
  int from, to, cost;
};

class kruskal{
  private:
    std::vector<edge> es;
    const int Node_size;
    const int Path_size;
  public:
    static bool comp(const edge& e1, const edge& e2) {
      return e1.cost < e2.cost;
    }
    kruskal(const int& V, const int& E, const std::vector<edge>& path) : es(path), Node_size(V), Path_size(E) {}
    int shortest_path(const int& start, const int& end) {
      std::sort(es.begin(), es.end(), comp);
      UnionFind union_find(Node_size);
      int res = 0;
      for (auto i = 0;i < Path_size;++i) {
        edge e = es[i];
        if (!union_find.same(e.from, e.to)) {
          union_find.unite(e.from, e.to);
          res += e.cost;
        }
      }
      return res;
    }
};
