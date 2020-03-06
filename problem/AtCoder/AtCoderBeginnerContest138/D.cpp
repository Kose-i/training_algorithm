#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

using P = std::pair<int, int>;
#define fi first
#define se second

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

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

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N-1);
  vector<ll> B(N-1);
  rep(i,N-1) cin >> A[i] >> B[i];
  vector<ll> P(Q);
  vector<ll> X(Q);
  rep(i,Q) cin >> P[i] >> X[i];

  UnionFind family_tree(N+1);
  rep(i,N-1) {
    family_tree.unite(A[i], B[i]);
  }
  vector<char> bit_root(N+1, 1);
  vector<ll> union_root;
  srep(i,1,N+1) {
    if (bit_root[i] == 0) continue;
    srep(j,i+1,N) {
      if (bit_root[j] == 0) continue;
      if (family_tree.same(i,j)) {
        bit_root[j] = 0;
      }
    }
    bit_root[i] = 0;
    union_root.push_back(i);
  }
  int union_root_size = union_root.size();
  vector<ll> union_root_value(union_root_size, 0);


  rep(i,Q) {
    for (const auto& e : union_root) {
      if (family_tree.same(P[i], e)) {
        union_root_value[e] += X[i];
        break;
      }
    }
  }

  for (const auto& e : union_root_value) {
    cout << e << ' ';
  }
  cout << '\n';

  vector<ll> answer(N+1, 0);
  srep(i,1,N+1) {
    if (answer[i] != 0) continue;
    for (auto j = 0;j < union_root_size;++j) {
      if (family_tree.same(union_root[j], i)) {
        answer[i] = union_root_value[j];
        break;
      }
    }
  }
  bool is_first = false;
  srep(i,1,N+1) {
    if (is_first) cout << ' ';
    else is_first = true;
    cout << answer[i];
  }
  cout << '\n';
}
