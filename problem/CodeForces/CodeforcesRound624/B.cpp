#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

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
  int t;
  std::cin >> t;
  std::vector<int> n(t);
  std::vector<int> m(t);
  std::vector<std::vector<int>> a(t, std::vector<int>());
  std::vector<std::vector<int>> p(t, std::vector<int>());
  rep(i,t) {
    std::cin >> n[i] >> m[i];
    std::vector<int> a_tmp(n[i]);
    std::vector<int> p_tmp(m[i]);
    rep(j,n[i]) std::cin >> a_tmp[j];
    rep(j,m[i]) std::cin >> p_tmp[j];
    a[i] = a_tmp;
    p[i] = p_tmp;
  }
  rep(i,t) {
    std::vector<int> a_cp = a[i];
    std::sort(a_cp.begin(), a_cp.end());
    UnionFind test(n[i]+1);
    rep(j,m[i]) test.unite(p[i][j]-1, p[i][j]); // index search
    std::vector<char> used(n[i], 0);
    bool is_find_error = false;
    rep(j, n[i]) {
      bool find = false;
      rep(k, n[i]) {
        if (a_cp[j] == a[i][k] && used[k] == 0 && test.same(k,j)) {
          find = true;
          used[k] = 1;
        }
      }
      if (find == false) {
        is_find_error = true;
        break;
      }
    }
    if (is_find_error == false) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
