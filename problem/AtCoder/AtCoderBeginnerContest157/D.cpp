#include <iostream>
#include <vector>

#define rep(i,n) for(int i = 0;i < (n);++i)
using ll = long long;

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
  ll N, M, K;
  std::cin >> N >> M >> K;


  std::vector<int> friend_list(N+1, 0);
  std::vector<int> block_list(N+1, 0);
  UnionFind friend_res_make(N+1);
  rep(i, M) {
    int a, b;
    std::cin >> a >> b;
    friend_res_make.unite(a, b);
    ++friend_list[a];
    ++friend_list[b];
  }
  rep(i, K) {
    int a, b;
    std::cin >> a >> b;
    if (friend_res_make.same(a, b)) {
      ++block_list[a];
      ++block_list[b];
    }
  }
  std::vector<int> friend_res(N+1, 0);
  for (int i = 1;i <= N;++i) {
    if (friend_res[i] == 0) {
      std::vector<int> index_same;
      for (int j = i+1;j <= N;++j) {
        if (friend_res[j] == 0 && friend_res_make.same(i,j)) {
          ++friend_res[i];
          index_same.push_back(j);
        }
      }
      for (const auto& e : index_same) {
        friend_res[e] = friend_res[i];
      }
    }
  }
  bool is_first = true;
  for (int i = 1;i <= N;++i) {
    if (is_first == false) std::cout << ' ';
    else is_first = false;
    std::cout << (friend_res[i] - friend_list[i] - block_list[i]);
  }
  std::cout << '\n';
}
