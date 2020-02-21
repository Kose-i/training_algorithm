#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)
#include <utility>
using P = std::pair<int, int>;

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

int main(int argc, char** argv) {
  ll N, K;
  std::cin >> N >> K;
  std::vector<P> tree(N);
  rep(i, N-1) std::cin >> tree[i].first >> tree[i].second;
  UnionFind f(N+1);
  rep(i, N-1) f.unite(tree[i].first, tree[i].second);

  ll sum {};
  for(auto i = 1;i <= N;++i) {
    if (f.same(1, i)) ++sum;
  }
  if (sum < K || N < K) {
    std::cout << "-1\n";
  } else {
    std::cout << K-1 << '\n';
  }
}
