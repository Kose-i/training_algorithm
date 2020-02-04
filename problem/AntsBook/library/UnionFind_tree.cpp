#include <vector>

class UnionFind{
  private:
    std::vector<int> parent; // if (parent[i] == i) ==> parent[i] is root
    std::vector<int> rank;
  public:
    UnionFind(const int& N) :parent(N), rank(N, 0) {
      for (auto i = 0;i < N;++i) {
        parent[i] = i;
      }
    }
    int find(const int& x) { // find tree root
      if (parent[x] == x) return x;
      else return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) { // x-tree add y-tree
      x = find(x);
      y = find(y);
      if (x == y) return;

      if (rank[x] < rank[y]) {
        parent[x] = y;
      } else {
        parent[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
      }
    }
    bool same(const int& x, const int& y) {
      return find(x) == find(y);
    }
};
